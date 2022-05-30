/** @file

  Copyright 2020 NXP

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Base.h>
#include <Uefi/UefiBaseType.h>
#include <Library/DebugLib.h>
#include <Library/LcdPlatformLib.h>
#include <Library/TimerLib.h>

#include <iMXDisplay.h>
#include <iMXI2cLib.h>
#include <adv7535.h>

#define CHECK_I2C_TRANSACTION_STATUS(status, message, label) \
            if (status != EFI_SUCCESS) { \
              DEBUG((DEBUG_ERROR, "ADV7535 i2c error. Register: %a, i2cStatus: %d\n", message, status)); \
              goto label; \
            }

#define IMX_HDMI_EDID_I2C_ADDRESS 0x7E

#define NUM_DSI_LANES 4U

/*
 * Configuration of the I2C device to be used for comunication with external MIPI DSI to HDMI converter ADV7535.
 */
IMX_I2C_CONTEXT I2C_ADV7535Config = {
    (uintptr_t)FixedPcdGet32(PcdDisplayI2CBaseAddr), /* Base address of the I2C block used for  communication with display */
    0x00,                                            /* iMX I2C Controller SlaveAddress - not used, I2C interface is used in master mode only */ 
    24000000,                                        /* 24Mhz I2C ReferenceFreq */
    400000,                                          /* 400KHz required TargetFreq */
    ADV7535_MAIN_IIC_SLAVE_ADDR,                     /* ADV7535 SlaveAddress */
    100000,                                          /* TimeoutInUs */
    };

/*
 * I2C configuration to be used for EDID reading.
 */
IMX_I2C_CONTEXT I2C_EdidConfig = {
    (uintptr_t)FixedPcdGet32(PcdDisplayI2CBaseAddr), /* Base address of the I2C block used for  communication with display */
    0x00,                                            /* iMX I2C Controller SlaveAddress - not used, I2C interface is used in master mode only */
    24000000,                                        /* 24Mhz I2C ReferenceFreq */
    400000,                                          /* 400KHz required TargetFreq */
    IMX_HDMI_EDID_I2C_ADDRESS,                       /* EDID I2C SlaveAddress */
    100000,                                          /* TimeoutInUs */
    };

/*
 * I2C configuration to be used for CEC configuration.
 */
IMX_I2C_CONTEXT I2C_CecConfig = {
    (uintptr_t)FixedPcdGet32(PcdDisplayI2CBaseAddr), /* Base address of the I2C block used for  communication with display */
    0x00,                                            /* iMX I2C Controller SlaveAddress - not used, I2C interface is used in master mode only */
    24000000,                                        /* 24Mhz I2C ReferenceFreq */
    400000,                                          /* 400KHz required TargetFreq */
    0,                                               /* CEC I2C SlaveAddress - will read from ADV7535 main map a configured during runtime */
    100000,                                          /* TimeoutInUs */
    };    

/**
  Check presence of ADV7535 by read of chip ID.

  @retval EFI_SUCCESS            ADV7535 search SUCCEDED.
  @retval EFI_DEVICE_ERROR       ADV7535 not found.

**/
EFI_STATUS Adv7535Discover
  (
    VOID
  )
{
  EFI_STATUS status;
  uint8_t i2cData[2];

  status = iMXI2cRead(&I2C_ADV7535Config, ADV7535_REG_CHIP_REVISION, &i2cData[0], 2);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_CHIP_REVISION", End);
  if (!status && i2cData[0] == ADV7535_REG_CHIP_REVISION_VALUE) {
      status = EFI_SUCCESS;
  }
End:
  return status;
}

/**
  Read EDID via ADV7535.

  @retval EFI_SUCCESS            ADV7535 EDID read completed successfully.
  @retval EFI_DEVICE_ERROR       ADV7535 not found.

**/
EFI_STATUS Adv7535ReadEdid
  (
    OUT uint8_t *edid,
    IN uint32_t offset,
    IN uint32_t length
  )
{
  EFI_STATUS status = EFI_SUCCESS;
  uint8_t  i2cData[4U];
  uint8_t  segment = (offset + length) / 256U;
  uint8_t  buf0;
  uint8_t  buf1;
  uint32_t idx = 0U;

  /* Read and configure the I2C slave address of the EDID memory of the LCD panel */ 
  status = iMXI2cRead(&I2C_ADV7535Config, ADV7535_REG_EDID_ADDR, &i2cData[0], 2);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_EDID_ADDR", End);
  I2C_EdidConfig.SlaveAddress = (i2cData[0] >> 1);
  DEBUG ((DEBUG_INFO, "ADV7535_REG_EDID_ADDR=0x%02X, status=%d\n", i2cData[0], status));

   /* Set segment */
  i2cData[0] = segment;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_EDID_SEGMENT, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_EDID_SEGMENT", End);
  /* HPD Override, and power up */
  i2cData[0] = ADV7535_REG_HPD_OVERRIDE__ENABLE;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_HPD_OVERRIDE, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_HPD_OVERRIDE", End);
  i2cData[0] = (ADV7535_REG_PD_RESET__POWER_UP | ADV7535_REG_PD_RESET__FIXED);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PD_RESET, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PD_RESET", End);
  /* Force EDID re-read */
  i2cData[0] = (ADV7535_REG_EDID__REREAD | ADV7535_REG_EDID__TRIES_3);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_EDID, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_EDID", End);

  /* Check HDMI communication result */
  do {
    buf0 = 0xFF;
    buf1 = 0xFF;
    MicroSecondDelay(1);
    status = iMXI2cRead(&I2C_ADV7535Config, ADV7535_REG_HDCP_STATE, &buf0, 2);
    CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_HDCP_STATE", End);
    status = iMXI2cRead(&I2C_ADV7535Config, ADV7535_REG_INT, &buf1, 2);
    CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_INT", End);
    if (idx++ > 1000U) { /* Handle timeout */
      DEBUG ((DEBUG_ERROR, "ADV7535 EDID OR HDCP NOT READY!!!\n"));
      return EFI_DEVICE_ERROR;
    }
  } while ((buf0 != ADV7535_REG_HDCP_STATE__IDLE) || ((buf1 & ADV7535_REG_INT__EDID_READY) == 0));

  /* Clear EDID_READY flag */
  i2cData[0] = ADV7535_REG_INT__EDID_READY;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_EDID, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_EDID", End);

  /* Read edid structure */
  for (int edid_reg_idx = offset; edid_reg_idx < offset+length; edid_reg_idx++) {
     status = iMXI2cRead(&I2C_EdidConfig, edid_reg_idx, &edid[edid_reg_idx-offset], 2);
     CHECK_I2C_TRANSACTION_STATUS(status, "EDID_DATA", End);
  }

End:
  return status;
}

/**
  Configure ADV7535 to required timing mode.

  @param[in] TimingMode          Timing mode to be set.

  @retval EFI_SUCCESS            ADV7535 timing mode set successfully.
  @retval EFI_DEVICE_ERROR       ADV7535 not found.

**/
EFI_STATUS Adv7535SetMode
  (
    IN IMX_DISPLAY_TIMING *PreferredTiming
  )
{
  EFI_STATUS status = EFI_SUCCESS;
  uint8_t    i2cData[2];
  uint32_t   sum;

  /* Read address of CEC & DSI memory map */
  status = iMXI2cRead(&I2C_ADV7535Config, ADV7535_REG_DSI_CEC_ADDR, &i2cData[0], 2);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DSI_CEC_ADDR", End);
  I2C_CecConfig.SlaveAddress = (i2cData[0] >> 1U);

  /* Power down */
  i2cData[0] = (ADV7535_REG_PD_RESET__POWER_DOWN | ADV7535_REG_PD_RESET__FIXED);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PD_RESET, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PD_RESET", End);

  /* HPD Override */
  i2cData[0] = (ADV7535_REG_HPD_OVERRIDE__ENABLE);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_HPD_OVERRIDE, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_HPD_OVERRIDE", End);

  /* Power up */
  i2cData[0] = (ADV7535_REG_PD_RESET__POWER_UP | ADV7535_REG_PD_RESET__FIXED);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PD_RESET, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PD_RESET", End);

  /* Activate Reset */
  i2cData[0] = (ADV7535_REG_PD_RESET__POWER_UP | ADV7535_REG_PD_RESET__FIXED | ADV7535_REG_PD_RESET__RESET_ENABLED);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PD_RESET, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PD_RESET", End);

  /* Deactivate reset */
  i2cData[0] = (ADV7535_REG_PD_RESET__POWER_UP | ADV7535_REG_PD_RESET__FIXED);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PD_RESET, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PD_RESET", End);

  /*  Reset CEC */
  i2cData[0] = ADV7535_REG_DSI_CEC_PD__RESET;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_DSI_CEC_PD, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DSI_CEC_PD", End);

  /*  Power up CEC */
  i2cData[0] = ADV7535_REG_DSI_CEC_PD__POWER_UP;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_DSI_CEC_PD, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DSI_CEC_PD", End);

  /* Fixed init */
  i2cData[0] = ADV7535_REG_HDCP_RI__FIXED;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_HDCP_RI, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_HDCP_RI", End);
  i2cData[0] = ADV7535_REG_MAIN_FIXED_0XDE__FIXED;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_MAIN_FIXED_0XDE, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_MAIN_FIXED_0XDE", End);
  i2cData[0] = ADV7535_REG_V1P8__FIXED;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_V1P8, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_V1P8", End);
  i2cData[0] = ADV7535_REG_MAIN_FIXED_0XE5__FIXED;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_MAIN_FIXED_0XE5, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_MAIN_FIXED_0XE5", End);
  i2cData[0] = ADV7535_REG_CECDSI_FIXED_0X15__FIXED;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X15, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_CECDSI_FIXED_0X15", End);
  i2cData[0] = ADV7535_REG_CECDSI_FIXED_0X17__FIXED;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X17, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_CECDSI_FIXED_0X17", End);
  i2cData[0] = ADV7535_REG_CECDSI_FIXED_0X24__FIXED;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X24, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_CECDSI_FIXED_0X24", End);
  i2cData[0] = ADV7535_REG_CECDSI_FIXED_0X57__FIXED;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X57, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_CECDSI_FIXED_0X57", End);

  /* Number of data lanes */
  i2cData[0] = ADV7535_REG_NUM_DSI_DATA_LANES__VALUE(NUM_DSI_LANES);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_NUM_DSI_DATA_LANES, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_NUM_DSI_DATA_LANES", End);

  /* Manual pixel clock divider = (bpp/8) * (4/num_lines), bpp can only be 24, so divider = 12/num_lines */
  int clkDivider = (PreferredTiming->Bpp / 8) * ( 4 / NUM_DSI_LANES);
  i2cData[0] =  (ADV7535_REG_PIX_CLK_DIV__MANUAL | ADV7535_REG_PIX_CLK_DIV__VALUE(clkDivider));
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_PIX_CLK_DIV, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PIX_CLK_DIV", End);

  /* Timing generator enable */
  i2cData[0] = (ADV7535_REG_TIMING_GEN__ENABLE | ADV7535_REG_TIMING_GEN__RESET_EN | ADV7535_REG_TIMING_GEN__FIXED);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TIMING_GEN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TIMING_GEN", End);

  /* Video mode configuration */
  /* Horizontal timing cfg */
  sum = PreferredTiming->HActive + PreferredTiming->HBlank;
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_FRM_WIDTH_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_FRM_WIDTH_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_FRM_WIDTH_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_FRM_WIDTH_LOW", End);
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(PreferredTiming->HSync);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_HSYNC_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_HSYNC_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(PreferredTiming->HSync);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_HSYNC_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_HSYNC_LOW", End);
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(PreferredTiming->HSyncOffset);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_HFP_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_HFP_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(PreferredTiming->HSyncOffset);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_HFP_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_HFP_LOW", End);
  sum = PreferredTiming->HBlank - PreferredTiming->HSyncOffset - PreferredTiming->HSync;
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_HBP_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_HBP_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_HBP_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_HBP_LOW", End);

  /* Vertical timing cfg */
  sum = PreferredTiming->VActive + PreferredTiming->VBlank;
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_FRM_HEIGHT_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_FRM_HEIGHT_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_FRM_HEIGHT_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_FRM_HEIGHT_LOW", End);
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(PreferredTiming->VSync);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_VSYNC_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_VSYNC_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(PreferredTiming->VSync);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_VSYNC_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_VSYNC_LOW", End);
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(PreferredTiming->VSyncOffset);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_VFP_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_VFP_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(PreferredTiming->VSyncOffset);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_VFP_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_VFP_LOW", End);
  sum = PreferredTiming->VBlank - PreferredTiming->VSyncOffset - PreferredTiming->VSync;
  i2cData[0] = ADV7535_REG_TG__HIGH_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_VBP_HIGH, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_VBP_HIGH", End);
  i2cData[0] = ADV7535_REG_TG__LOW_VAL(sum);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TG_VBP_LOW, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TG_VBP_LOW", End);

  /* Timing generator reset */
  i2cData[0] = (ADV7535_REG_TIMING_GEN__ENABLE | ADV7535_REG_TIMING_GEN__RESET_EN | ADV7535_REG_TIMING_GEN__FIXED);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TIMING_GEN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TIMING_GEN", End);
  i2cData[0] = (ADV7535_REG_TIMING_GEN__ENABLE | ADV7535_REG_TIMING_GEN__RESET_DIS | ADV7535_REG_TIMING_GEN__FIXED);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TIMING_GEN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TIMING_GEN", End);
  i2cData[0] = (ADV7535_REG_TIMING_GEN__ENABLE | ADV7535_REG_TIMING_GEN__RESET_EN | ADV7535_REG_TIMING_GEN__FIXED);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_TIMING_GEN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_TIMING_GEN", End);

  /* Pattern generator disable */
  i2cData[0] = ADV7535_REG_PATTERN_GEN__DISABLE;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_PATTERN_GEN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PATTERN_GEN", End);

  /* Clear status - togle to 0 and back to 1 */
  i2cData[0] = 0;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_DSI_STATUS, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DSI_STATUS", End);

  i2cData[0] = ADV7535_REG_DSI_STATUS__STATUS_CLR;
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_DSI_STATUS, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DSI_STATUS", End);

  /* AVI Info-frame */
  /* No aspect ratio. It is possible to select 16:9 or 4:3 aspect ratio, but need to be determined from EDID */
  i2cData[0] = (ADV7535_REG_AVI_INFOFRM_0X56__C1C0_NODATA | ADV7535_REG_AVI_INFOFRM_0X56__M1M0_NODATA | 
                ADV7535_REG_AVI_INFOFRM_0X56__R_NDEF);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_AVI_INFOFRM_0X56, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_AVI_INFOFRM_0X56", End);
  /* AVI Info-frame - active format valid */
  i2cData[0] = (ADV7535_REG_AVI_INFOFRM_0X55__ACTIVE_VAL | ADV7535_REG_AVI_INFOFRM_0X55__Y1Y0_RGB |
               ADV7535_REG_AVI_INFOFRM_0X55__B1B0_NOBAR | ADV7535_REG_AVI_INFOFRM_0X55__S1S0_NOINFO);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_AVI_INFOFRM_0X55, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_AVI_INFOFRM_0X55", End);
  /* GC packet enable 0x40 */
  i2cData[0] = ADV7535_REG_PACKET__GC_PKT_EN;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PACKET, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PACKET", End);
  /* Enable other packets - 0x44 - default state */
  i2cData[0] = (ADV7535_REG_PACKET2__NCTS_PKT_EN | ADV7535_REG_PACKET2__AUD_SAMP_PKT_EN | 
                ADV7535_REG_PACKET2__AVIIF_PKT_EN | ADV7535_REG_PACKET2__AUDIOIF_PKT_EN | 
                ADV7535_REG_PACKET2__FIXED);
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_PACKET2, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_PACKET2", End);
  /* 24 bpp */
  i2cData[0] = ADV7535_REG_COL_DEP_DOWN__24BPP;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_COL_DEP_DOWN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_COL_DEP_DOWN", End);
  /* 8 bits */
  i2cData[0] = ADV7535_REG_DOWN_DITHER__COL_DEP_8;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_DOWN_DITHER, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DOWN_DITHER", End);
  /* HSYNC, VSYNC polarity, DE disable bits */
  i2cData[0] = 0;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_SYNC_POL_DE_EN, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_SYNC_POL_DE_EN", End);
  /* LIMIT: Only refresh rates 50Hz and higher supported. */
  i2cData[0] = ADV7535_REG_INFOFRM_0X4A__AUTO_CHKSUM_EN;
  status = iMXI2cWrite(&I2C_ADV7535Config, ADV7535_REG_INFOFRM_0X4A, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_INFOFRM_0X4A", End);

  /* CEC always active */
  i2cData[0] = (ADV7535_REG_CEC_CLK_PWR__CLKDIV(16) | ADV7535_REG_CEC_CLK_PWR__PWR_ACTIVE);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_CEC_CLK_PWR, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_CEC_CLK_PWR", End);
  /* HDMI out and LPOSC power up */
  i2cData[0] = (ADV7535_REG_HDMI_LPOSC__HDMI_OUT_EN | ADV7535_REG_HDMI_LPOSC__LPOSC_PWRUP | ADV7535_REG_HDMI_LPOSC__FIXED);
  status = iMXI2cWrite(&I2C_CecConfig, ADV7535_REG_HDMI_LPOSC, &i2cData[0], 1);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_HDMI_LPOSC", End);

  /* Post init dump */
  ADV7535Dump();

End:
  return status;
}

/**
  Dump required ADV7535 register for debug purposes.

  @retval EFI_SUCCESS            Register dump completed successfully.
  @retval EFI_DEVICE_ERROR       ADV7535 device error.

**/
EFI_STATUS Adv7535DumpRegister
  (
    IN IMX_I2C_CONTEXT *i2cConfig,
    IN uint8_t reg,
    IN char* reg_name
  )
{
  EFI_STATUS status;
  uint8_t i2cData[2];

  status = iMXI2cRead(i2cConfig, reg, &i2cData[0], 2);
  CHECK_I2C_TRANSACTION_STATUS(status, reg_name, End);
  DEBUG ((DEBUG_INFO, "%a = 0x%02X\n", reg_name, i2cData[0]));
End:
  return status;
}

/**
  Dump ADV7535 registers.

  @retval EFI_SUCCESS            ADV7535 register dump competed successfully.
  @retval EFI_DEVICE_ERROR       ADV7535 device error.

**/
EFI_STATUS ADV7535Dump
  (
  )
{
  EFI_STATUS status;
  uint8_t i2cData[2];

  /* Read address of CEC & DSI memory map */
  status = iMXI2cRead(&I2C_ADV7535Config, ADV7535_REG_DSI_CEC_ADDR, &i2cData[0], 2);
  CHECK_I2C_TRANSACTION_STATUS(status, "ADV7535_REG_DSI_CEC_ADDR", End);
  I2C_CecConfig.SlaveAddress = (i2cData[0] >> 1U);

  DEBUG ((DEBUG_INFO, "------------------------ADV7535 Main Space------------------------\n"));
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_PD_RESET, "ADV7535_REG_PD_RESET");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_HPD_OVERRIDE, "ADV7535_REG_HPD_OVERRIDE");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_COL_SPACE, "ADV7535_REG_COL_SPACE");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_MAIN_FIXED_0X9A, "ADV7535_REG_MAIN_FIXED_0X9A");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_HDCP_RI, "ADV7535_REG_HDCP_RI");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_MAIN_FIXED_0XDE, "ADV7535_REG_MAIN_FIXED_0XDE");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_V1P8, "ADV7535_REG_V1P8");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_MAIN_FIXED_0XE5, "ADV7535_REG_MAIN_FIXED_0XE5");
  DEBUG ((DEBUG_INFO, "------------------------ADV7535 CEC_DSI Space------------------------\n"));
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X15, "ADV7535_REG_CECDSI_FIXED_0X15");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X17, "ADV7535_REG_CECDSI_FIXED_0X17");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X24, "ADV7535_REG_CECDSI_FIXED_0X24");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_CECDSI_FIXED_0X57, "ADV7535_REG_CECDSI_FIXED_0X57");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_NUM_DSI_DATA_LANES, "ADV7535_REG_NUM_DSI_DATA_LANES");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_PIX_CLK_DIV, "ADV7535_REG_PIX_CLK_DIV");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TIMING_GEN, "ADV7535_REG_TIMING_GEN");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_FRM_WIDTH_HIGH, "ADV7535_REG_TG_FRM_WIDTH_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_FRM_WIDTH_LOW, "ADV7535_REG_TG_FRM_WIDTH_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_HSYNC_HIGH, "ADV7535_REG_TG_HSYNC_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_HSYNC_LOW, "ADV7535_REG_TG_HSYNC_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_HFP_HIGH, "ADV7535_REG_TG_HFP_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_HFP_LOW, "ADV7535_REG_TG_HFP_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_HBP_HIGH, "ADV7535_REG_TG_HBP_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_HBP_LOW, "ADV7535_REG_TG_HBP_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_FRM_HEIGHT_HIGH, "ADV7535_REG_TG_FRM_HEIGHT_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_FRM_HEIGHT_LOW, "ADV7535_REG_TG_FRM_HEIGHT_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_VSYNC_HIGH, "ADV7535_REG_TG_VSYNC_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_VSYNC_LOW, "ADV7535_REG_TG_VSYNC_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_VFP_HIGH, "ADV7535_REG_TG_VFP_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_VFP_LOW, "ADV7535_REG_TG_VFP_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_VBP_HIGH, "ADV7535_REG_TG_VBP_HIGH");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TG_VBP_LOW, "ADV7535_REG_TG_VBP_LOW");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_TIMING_GEN, "ADV7535_REG_TIMING_GEN");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_PATTERN_GEN, "ADV7535_REG_PATTERN_GEN");
  DEBUG ((DEBUG_INFO, "------------------------ADV7535 Main Space------------------------\n"));
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_HDCP_VOUT_SEL, "ADV7535_REG_HDCP_VOUT_SEL");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_AVI_INFOFRM_0X55, "ADV7535_REG_AVI_INFOFRM_0X55");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_AVI_INFOFRM_0X56, "ADV7535_REG_AVI_INFOFRM_0X56");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_PACKET, "ADV7535_REG_PACKET");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_PACKET2, "ADV7535_REG_PACKET2");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_COL_DEP_DOWN, "ADV7535_REG_COL_DEP_DOWN");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_DOWN_DITHER, "ADV7535_REG_DOWN_DITHER");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_SYNC_POL_DE_EN, "ADV7535_REG_SYNC_POL_DE_EN");
  Adv7535DumpRegister(&I2C_ADV7535Config, ADV7535_REG_INFOFRM_0X4A, "ADV7535_REG_INFOFRM_0X4A");
  DEBUG ((DEBUG_INFO, "------------------------ADV7535 CEC_DSI Space------------------------\n"));
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_CEC_CLK_PWR, "ADV7535_REG_CEC_CLK_PWR");
  Adv7535DumpRegister(&I2C_CecConfig, ADV7535_REG_HDMI_LPOSC, "ADV7535_REG_HDMI_LPOSC");
End:
  return status;
}

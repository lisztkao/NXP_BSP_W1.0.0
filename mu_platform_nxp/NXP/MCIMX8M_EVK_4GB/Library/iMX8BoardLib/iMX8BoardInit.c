/** @file
*
*  Copyright (c) Microsoft Corporation. All rights reserved.
*  Copyright 2019-2020 NXP
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#include <Library/ArmPlatformLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/PrintLib.h>
#include <Library/PcdLib.h>
#include <Library/SerialPortLib.h>
#include <Library/TimerLib.h>
#include <Library/ArmSmcLib.h>
#include <Ppi/ArmMpCoreInfo.h>


#include "iMX8.h"
#include "iMX8ClkPwr.h"
#include "iMX8MIoMux.h"

#define IMX_SIP_CONFIG_GPC_PM_DOMAIN    0x03
#define IMX_PCIE1_PD                    1
#define IMX_USB1_PD                     2
#define IMX_USB2_PD                     3
#define IMX_GPU_BUS                     4
#define IMX_VPU_BUS                     5
#define IMX_VPU_G1                      6
#define IMX_VPU_G2                      7
#define IMX_VPU_H1                      8
#define IMX_PCIE2_PD                    10

#define IMX_VPU_BLK_CTL_BASE            0x38320000

ARM_CORE_INFO iMX8Ppi[] =
{
  {
    // Cluster 0, Core 0
    0x0, 0x0,
    // MP Core MailBox Set/Get/Clear Addresses and Clear Value.
    // Not used with i.MX8, set to 0
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (UINT64)0
  },
#if FixedPcdGet32(PcdCoreCount) > 1
  {
    // Cluster 0, Core 1
    0x0, 0x1,
    // MP Core MailBox Set/Get/Clear Addresses and Clear Value
    // Not used with i.MX8, set to 0
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (UINT64)0
  },
#endif // FixedPcdGet32(PcdCoreCount) > 1
#if FixedPcdGet32(PcdCoreCount) > 2
  {
    // Cluster 0, Core 2
    0x0, 0x2,
    // MP Core MailBox Set/Get/Clear Addresses and Clear Value
    // Not used with i.MX8, set to 0
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (UINT64)0
  },
  {
    // Cluster 0, Core 3
    0x0, 0x3,
    // MP Core MailBox Set/Get/Clear Addresses and Clear Value
    // Not used with i.MX8, set to 0
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (EFI_PHYSICAL_ADDRESS)0x00000000,
    (UINT64)0
  }
#endif // FixedPcdGet32(PcdCoreCount) > 2
};

EFI_STATUS PrePeiCoreGetMpCoreInfo(OUT UINTN *CoreCount, OUT ARM_CORE_INFO **ArmCoreTable)
{
  // Only support one cluster
  *CoreCount = sizeof(iMX8Ppi) / sizeof(ARM_CORE_INFO);
  ASSERT (*CoreCount == FixedPcdGet32 (PcdCoreCount));
  *ArmCoreTable = iMX8Ppi;
  return EFI_SUCCESS;
}

ARM_MP_CORE_INFO_PPI mMpCoreInfoPpi = { PrePeiCoreGetMpCoreInfo };

EFI_PEI_PPI_DESCRIPTOR  gPlatformPpiTable[] = {
  {
    EFI_PEI_PPI_DESCRIPTOR_PPI,
    &gArmMpCoreInfoPpiGuid,
    &mMpCoreInfoPpi
  }
};

VOID ArmPlatformGetPlatformPpiList(OUT UINTN *PpiListSize, OUT EFI_PEI_PPI_DESCRIPTOR **PpiList)
{
  *PpiListSize = sizeof(gPlatformPpiTable);
  *PpiList = gPlatformPpiTable;
}

/**
  Initalize the Audio system
**/
#define SAI_PAD_CFG_OUT (IOMUXC_PAD_PUE_ENABLE | IOMUXC_PAD_DSE_R0_DIV_3 | IOMUXC_PAD_SRE_FAST)
VOID AudioInit(VOID)
{
  EFI_STATUS status;
  // Mux the SAI2 pins to wm8524 codec
  IOMUXC_SW_MUX_CTL_PAD_SAI2_TXFS = IOMUXC_MUX_ALT0;
  IOMUXC_SW_MUX_CTL_PAD_SAI2_TXC  = IOMUXC_MUX_ALT0;
  IOMUXC_SW_MUX_CTL_PAD_SAI2_TXD0 = IOMUXC_MUX_ALT0;
  IOMUXC_SW_MUX_CTL_PAD_SAI2_MCLK = IOMUXC_MUX_ALT0;

  IOMUXC_SW_PAD_CTL_PAD_SAI2_TXFS = SAI_PAD_CFG_OUT;
  IOMUXC_SW_PAD_CTL_PAD_SAI2_TXC  = SAI_PAD_CFG_OUT;
  IOMUXC_SW_PAD_CTL_PAD_SAI2_TXD0 = SAI_PAD_CFG_OUT;
  IOMUXC_SW_PAD_CTL_PAD_SAI2_MCLK = SAI_PAD_CFG_OUT;
  // unmute audio
  IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO08 = IOMUXC_MUX_ALT0;
  GPIO1_DR   |= GPIO_DR_DR(1 << 8);
  GPIO1_GDIR |= GPIO_DR_DR(1 << 8);
  // enable the AUDIO_PLL - 44,100 Hz * 256
  status = ImxSetSAI2ClockRate (11289600);
  if (EFI_ERROR (status)) {
    DebugPrint (DEBUG_ERROR, "AudioInit - ImxSetAudioMclkClockRate failed");
  }
}

/**
  Initialize I2C modules on the SOC and perform required pin-muxing
**/
#define I2C_PAD_CTRL (IOMUXC_PAD_DSE_R0_DIV_3 | IOMUXC_PAD_SRE_SLOW | IOMUXC_PAD_ODE_ENABLED | \
                      IOMUXC_PAD_HYS_ENABLED | IOMUXC_PAD_PUE_ENABLE)
VOID I2cInit()
{
  IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL = IOMUXC_MUX_ALT0 | IOMUXC_MUX_SION_ENABLED;
  IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA = IOMUXC_MUX_ALT0 | IOMUXC_MUX_SION_ENABLED;
  IOMUXC_SW_MUX_CTL_PAD_I2C2_SCL = IOMUXC_MUX_ALT0 | IOMUXC_MUX_SION_ENABLED;
  IOMUXC_SW_MUX_CTL_PAD_I2C2_SDA = IOMUXC_MUX_ALT0 | IOMUXC_MUX_SION_ENABLED;
  IOMUXC_SW_MUX_CTL_PAD_I2C3_SCL = IOMUXC_MUX_ALT0 | IOMUXC_MUX_SION_ENABLED;
  IOMUXC_SW_MUX_CTL_PAD_I2C3_SDA = IOMUXC_MUX_ALT0 | IOMUXC_MUX_SION_ENABLED;

  IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL = I2C_PAD_CTRL;
  IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA = I2C_PAD_CTRL;
  IOMUXC_SW_PAD_CTL_PAD_I2C2_SCL = I2C_PAD_CTRL;
  IOMUXC_SW_PAD_CTL_PAD_I2C2_SDA = I2C_PAD_CTRL;
  IOMUXC_SW_PAD_CTL_PAD_I2C3_SCL = I2C_PAD_CTRL;
  IOMUXC_SW_PAD_CTL_PAD_I2C3_SDA = I2C_PAD_CTRL;
}

/**
  Initialize ENETs modules on the SOC and perform required pin-muxing.
**/
#define PIN_ENET_RST_B (1<<9)
#define ENET_MDC_PAD_CTRL     (IOMUXC_PAD_DSE_R0_DIV_3 | IOMUXC_PAD_SRE_SLOW)
#define ENET_MDIO_PAD_CTRL    (IOMUXC_PAD_DSE_R0_DIV_3 | IOMUXC_PAD_SRE_SLOW | IOMUXC_PAD_ODE_ENABLED)
#define ENET_TX_PAD_CTRL      (IOMUXC_PAD_DSE_R0_DIV_7 | IOMUXC_PAD_SRE_MAX)
#define ENET_RX_PAD_CTRL      (IOMUXC_PAD_DSE_R0_DIV_1 | IOMUXC_PAD_SRE_FAST | IOMUXC_PAD_HYS_ENABLED)
VOID EnetInit(VOID)
{
  // ENET1/2 MDIO bus (both ENETs share one MDIO bus conected to the ENET1 controller)
  IOMUXC_SW_MUX_CTL_PAD_ENET_MDC    = IOMUXC_MUX_ALT0;    // ENET1_MDC  -> PAD_GPIO1_IO11
  IOMUXC_SW_MUX_CTL_PAD_ENET_MDIO   = IOMUXC_MUX_ALT0;    // ENET1_MDIO -> PAD_PAD_ENET_MDIO
  IOMUXC_ENET1_MDIO_SELECT_INPUT    = IOMUXC_MUX_ALT1;    // ENET1_MDIO <- PAD_PAD_ENET_MDIO
  IOMUXC_SW_PAD_CTL_PAD_ENET_MDC    = ENET_MDC_PAD_CTRL;  // ENET1_MDC  electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_MDIO   = ENET_MDIO_PAD_CTRL; // ENET1_MDIO electrical settings
  // ENET1 RGMMI pins routing
  IOMUXC_SW_MUX_CTL_PAD_ENET_TD3    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_TD3    -> PAD_ENET1_TD3
  IOMUXC_SW_MUX_CTL_PAD_ENET_TD2    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_TD2    -> PAD_ENET1_TD2
  IOMUXC_SW_MUX_CTL_PAD_ENET_TD1    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_TD1    -> PAD_ENET1_TD1
  IOMUXC_SW_MUX_CTL_PAD_ENET_TD0    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_TD0    -> PAD_ENET1_TD0
  IOMUXC_SW_MUX_CTL_PAD_ENET_TX_CTL = IOMUXC_MUX_ALT0;    // ENET1_RGMII_TX_CTL -> PAD_ENET1_TX_CTL
  IOMUXC_SW_MUX_CTL_PAD_ENET_TXC    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_TXC    -> PAD_ENET1_TXC
  IOMUXC_SW_MUX_CTL_PAD_ENET_RD3    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_RD3    <- PAD_ENET1_RD3
  IOMUXC_SW_MUX_CTL_PAD_ENET_RD2    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_RD2    <- PAD_ENET1_RD2
  IOMUXC_SW_MUX_CTL_PAD_ENET_RD1    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_RD1    <- PAD_ENET1_RD1
  IOMUXC_SW_MUX_CTL_PAD_ENET_RD0    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_RD0    <- PAD_ENET1_RD0
  IOMUXC_SW_MUX_CTL_PAD_ENET_RX_CTL = IOMUXC_MUX_ALT0;    // ENET1_RGMII_RX_CTL <- PAD_ENET1_RX_CTL
  IOMUXC_SW_MUX_CTL_PAD_ENET_RXC    = IOMUXC_MUX_ALT0;    // ENET1_RGMII_RXC    <- PAD_ENET1_RXC
  // ENET1 RGMMI pins electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_RD3    = ENET_RX_PAD_CTRL;  // ENET1_RGMII_RD3    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_RD2    = ENET_RX_PAD_CTRL;  // ENET1_RGMII_RD2    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_RD1    = ENET_RX_PAD_CTRL;  // ENET1_RGMII_RD1    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_RD0    = ENET_RX_PAD_CTRL;  // ENET1_RGMII_RD0    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_RX_CTL = ENET_RX_PAD_CTRL;  // ENET1_RGMII_RX_CTL electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_RXC    = ENET_RX_PAD_CTRL;   // ENET1_RGMII_RXC    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_TD3    = ENET_TX_PAD_CTRL;  // ENET1_RGMII_TD3    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_TD2    = ENET_TX_PAD_CTRL;  // ENET1_RGMII_TD2    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_TD1    = ENET_TX_PAD_CTRL;  // ENET1_RGMII_TD1    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_TD0    = ENET_TX_PAD_CTRL;  // ENET1_RGMII_TD0    electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_TX_CTL = ENET_TX_PAD_CTRL;  // ENET1_RGMII_TX_CTL electrical settings
  IOMUXC_SW_PAD_CTL_PAD_ENET_TXC    = ENET_TX_PAD_CTRL;   // ENET1_RGMII_TXC    electrical settings
  // Configure ENET_nRST signal
  IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO09 = IOMUXC_MUX_ALT0;
  IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO09 = IOMUXC_PAD_DSE_R0_DIV_1 | IOMUXC_PAD_SRE_SLOW;
  GPIO1_DR &= ~PIN_ENET_RST_B;                                   // Set ENET_nRST = 0
  GPIO1_GDIR |= PIN_ENET_RST_B;                                  // Set direction to output
  MicroSecondDelay(500);
  GPIO1_DR |= PIN_ENET_RST_B;                                    // Set ENET_nRST = 1
  CCM_CCGR_ENET1 = 0x00000003;                                   // ENET1 clock gate
}

/**
  Initialize USBs modules on the SOC and perform required pin-muxing.
**/
#define PHY1_CTRL0_REG  0x00000000381F0040
#define PHY1_CTRL1_REG  0x00000000381F0044
#define PHY1_CTRL2_REG  0x00000000381F0048

#define PHY2_CTRL0_REG  0x00000000382F0040
#define PHY2_CTRL1_REG  0x00000000382F0044
#define PHY2_CTRL2_REG  0x00000000382F0048

#define PHY_CTRL0_REF_SSP_EN        (0x01 <<  2)
#define PHY_CTRL1_RESET             (0x01 <<  0)
#define PHY_CTRL1_ATERESET          (0x01 <<  3)
#define PHY_CTRL1_VDATSRCENB0       (0x01 << 19)
#define PHY_CTRL1_VDATDETENB0       (0x01 << 20)
#define PHY_CTRL2_TXENABLEN0        (0x01 <<  8)

#define RdReg32(_RegAddr)            ((UINT32)*((volatile UINT32*)(_RegAddr)))
#define WrReg32(_RegAddr, _RegVal)   *((volatile UINT32*)(_RegAddr)) = _RegVal;
VOID USBInit() {
  UINT32 reg;
  ARM_SMC_ARGS smc_args;

  /* Disable USB Controller 1 power domain */
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_USB1_PD, 0x01, 0x00, smc_args);
  ArmCallSmc(&smc_args);
  /* Disable USB Controller 2 power domain */
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_USB2_PD, 0x01, 0x00, smc_args);
  ArmCallSmc(&smc_args);
  /* Disable USB Controllers clock root */
  CCM_CCGR_CLR(CCM_CCGR_IDX_USB_CTRL1) = 0x03;
  CCM_CCGR_CLR(CCM_CCGR_IDX_USB_CTRL2) = 0x03;
  /* Disable USB PHYs clock root */
  CCM_CCGR_CLR(CCM_CCGR_IDX_USB_PHY1)  = 0x03;
  CCM_CCGR_CLR(CCM_CCGR_IDX_USB_PHY2)  = 0x03;
  CCM_TARGET_ROOT_USB_BUS      = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK; /* 500MHz, SYSTEM_PLL2_DIV2 */
  CCM_TARGET_ROOT_USB_CORE_REF = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK; /* 100MHz, SYSTEM_PLL1_DIV8 */
  CCM_TARGET_ROOT_USB_PHY_REF  = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK; /* 100MHz, SYSTEM_PLL1_DIV8 */
  /* Enable USB Controllers clock root */
  CCM_CCGR_SET(CCM_CCGR_IDX_USB_CTRL1) = 0x03;
  CCM_CCGR_SET(CCM_CCGR_IDX_USB_CTRL2) = 0x03;
  /* Enable USB USB PHYs clock root */
  CCM_CCGR_SET(CCM_CCGR_IDX_USB_PHY1)  = 0x03;
  CCM_CCGR_SET(CCM_CCGR_IDX_USB_PHY2)  = 0x03;

  /* Configure USB USB PHY 1 */
  reg = RdReg32(PHY1_CTRL1_REG);
  reg &= ~(PHY_CTRL1_VDATSRCENB0 | PHY_CTRL1_VDATDETENB0);
  reg |= PHY_CTRL1_RESET | PHY_CTRL1_ATERESET;
  WrReg32(PHY1_CTRL1_REG, reg);

  reg = RdReg32(PHY1_CTRL0_REG);
  reg |= PHY_CTRL0_REF_SSP_EN;
  WrReg32(PHY1_CTRL0_REG, reg);

  reg = RdReg32(PHY1_CTRL2_REG);
  reg |= PHY_CTRL2_TXENABLEN0;
  WrReg32(PHY1_CTRL2_REG, reg);

  reg = RdReg32(PHY1_CTRL1_REG);
  reg &= ~(PHY_CTRL1_RESET | PHY_CTRL1_ATERESET);
  WrReg32(PHY1_CTRL1_REG, reg);

  /* Configure USB USB PHY 2 */
  reg = RdReg32(PHY2_CTRL1_REG);
  reg &= ~(PHY_CTRL1_VDATSRCENB0 | PHY_CTRL1_VDATDETENB0);
  reg |= PHY_CTRL1_RESET | PHY_CTRL1_ATERESET;
  WrReg32(PHY2_CTRL1_REG, reg);

  reg = RdReg32(PHY2_CTRL0_REG);
  reg |= PHY_CTRL0_REF_SSP_EN;
  WrReg32(PHY2_CTRL0_REG, reg);

  reg = RdReg32(PHY2_CTRL2_REG);
  reg |= PHY_CTRL2_TXENABLEN0;
  WrReg32(PHY2_CTRL2_REG, reg);

  reg = RdReg32(PHY2_CTRL1_REG);
  reg &= ~(PHY_CTRL1_RESET | PHY_CTRL1_ATERESET);
  WrReg32(PHY2_CTRL1_REG, reg);
};


#if (FixedPcdGet32(PcdPcie1Enable) || FixedPcdGet32(PcdPcie2Enable))
/**
  Initialize PCI Express module on the SOC and perform required pin-muxing
**/
VOID PcieInit ()
{
  ARM_SMC_ARGS smc_args;

  /* Enable PCIe1 power domain */
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_PCIE1_PD, 0x01, 0x00, smc_args);
  ArmCallSmc(&smc_args);
  /* Enable PCIe2 power domain */
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_PCIE2_PD, 0x01, 0x00, smc_args);
  ArmCallSmc(&smc_args);

#if FixedPcdGet32(PcdPcie1Enable)
  /* Disable PCIE_CTRL clock root */
  CCM_CCGR_CLR(37) = 0x03;
  /* Set PCIe controller input clock to 250MHz (SYSTEM_PLL2_DIV4) */
  CCM_TARGET_ROOT(70) = CCM_TARGET_ROOT_MUX(0x01);
  CCM_TARGET_ROOT_SET(70) = CCM_TARGET_ROOT_ENABLE_MASK;
  /* Set PCIe PHy input clock to 100MHz (SYSTEM_PLL2_DIV10) */
  CCM_TARGET_ROOT(71) = CCM_TARGET_ROOT_MUX(0x01);
  CCM_TARGET_ROOT_SET(71) = CCM_TARGET_ROOT_ENABLE_MASK;
  /* Set PCIe AUX input clock to 10MHz (SYSTEM_PLL2_DIV20 / 5) */
  CCM_TARGET_ROOT(72) = CCM_TARGET_ROOT_MUX(0x02) | CCM_TARGET_ROOT_POST_PODF(4);
  CCM_TARGET_ROOT_SET(72) = CCM_TARGET_ROOT_ENABLE_MASK;
  /* Enable PCIE_CTRL clock root */
  CCM_CCGR_SET(37) = 0x03;

  /* Configure NAND_DQS as GPIO to control PCIe WL_nWAKE PAD */
  IOMUXC_SW_MUX_CTL_PAD_NAND_DQS = IOMUXC_MUX_ALT5;
  GPIO3_GDIR &= ~(0x01 << 14);                   /* Set input direction */

  /* Configure UART4_RXD as GPIO to control PCIe WL_nPERST PAD */
  IOMUXC_SW_MUX_CTL_PAD_UART4_RXD = IOMUXC_MUX_ALT5;
  GPIO5_DR &= ~(0x01 << 28);                    /* Set the pad to the low level */
  GPIO5_GDIR |= (0x01 << 28);                   /* Set output direction */

  /* Configure UART4_TXD to control PCIe WL_REG_ON PAD */
  IOMUXC_SW_MUX_CTL_PAD_UART4_TXD = IOMUXC_MUX_ALT5;
  GPIO5_DR |= (0x01 << 29);                     /* Set the pad to the high level */
  GPIO5_GDIR |= (0x01 << 29);                   /* Set output direction */
#endif
#if FixedPcdGet32(PcdPcie2Enable)
  /* Disable PCIE_CTRL clock root */
  CCM_CCGR_CLR(100) = 0x03;
  /* Set PCIe controller input clock to 250MHz (SYSTEM_PLL2_DIV4) */
  CCM_TARGET_ROOT(128) = CCM_TARGET_ROOT_MUX(0x01);
  CCM_TARGET_ROOT_SET(128) = CCM_TARGET_ROOT_ENABLE_MASK;
  /* Set PCIe PHy input clock to 100MHz (SYSTEM_PLL2_DIV10) */
  CCM_TARGET_ROOT(129) = CCM_TARGET_ROOT_MUX(0x01);
  CCM_TARGET_ROOT_SET(129) = CCM_TARGET_ROOT_ENABLE_MASK;
  /* Set PCIe AUX input clock to 10MHz (SYSTEM_PLL2_DIV20 / 5) */
  CCM_TARGET_ROOT(130) = CCM_TARGET_ROOT_MUX(0x02) | CCM_TARGET_ROOT_POST_PODF(4);
  CCM_TARGET_ROOT_SET(130) = CCM_TARGET_ROOT_ENABLE_MASK;
  /* Enable PCIE_CTRL clock root */
  CCM_CCGR_SET(100) = 0x03;

  /* Configure ECSPI2_MOSI as GPIO to control PCIe nWAKE PAD */
  IOMUXC_SW_MUX_CTL_PAD_ECSPI2_MOSI = IOMUXC_MUX_ALT5;
  GPIO5_GDIR &= ~(0x01 << 7);                   /* Set input direction */

  /* Configure ECSPI2_MISO as GPIO to control PCIe nPERST PAD */
  IOMUXC_SW_MUX_CTL_PAD_ECSPI2_MISO = IOMUXC_MUX_ALT5;
  GPIO5_DR &= ~(0x01 << 12);                    /* Set the pad to the low level */
  GPIO5_GDIR |= (0x01 << 12);                   /* Set output direction */

  /* Configure ECSPI2_SCLK to control PCIe nDISABLE PAD */
  IOMUXC_SW_MUX_CTL_PAD_ECSPI2_SCLK = IOMUXC_MUX_ALT5;
  GPIO5_DR |= (0x01 << 10);                     /* Set the pad to the high level */
  GPIO5_GDIR |= (0x01 << 10);                   /* Set output direction */
#endif
}
#endif

/**
  Initialize PWM block and perform required pin-muxing.
**/
VOID PwmInit()
{
  int pwm_ccgr_offset = 40;
  int pwm_clk_root_offset = 103;

  /* Initialize PWM1-PWM4 clocks */
  for(int i = 0; i < 4; i++)
  {
  CCM_CCGR_CLR(pwm_ccgr_offset + i) = 0x03;
  CCM_TARGET_ROOT(pwm_clk_root_offset + i) = (CCM_TARGET_ROOT_MUX(0x00) | CCM_TARGET_ROOT_ENABLE_MASK);       /* Set 25M_REF_CLK as PWM input clock, no PRE nor POST divider, Enable PWM clock */
  CCM_CCGR_SET(pwm_ccgr_offset + i) = 0x03;
  }

  /* Configure GPIO1_IO01 as PWM1_OUT */
  IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO01 = IOMUXC_MUX_ALT1;
  IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO01 = (IOMUXC_SW_PAD_CTL_PAD_DSE(4) | /* Drive strength 85 Ohm @3.3V, 80 Ohm @2.5V, 75 Ohm @1.8V, 90 Ohm @1.2V */
                                      IOMUXC_SW_PAD_CTL_PAD_SRE(0)); /* Slow Frequency Slew Rate (50Mhz) */
}

/**
  Initialize VPU_PLL block.
**/
static VOID VpuPllInit()
{
  INT32 count;

  // Bypass the VPU PLL clock
  CCM_ANALOG_VPU_PLL_CFG0 |= CCM_ANALOG_VPU_PLL_CFG0_PLL_BYPASS_MASK;

  CCM_ANALOG_VPU_PLL_CFG1 = CCM_ANALOG_VPU_PLL_CFG1_PLL_INT_DIV_CTL(59);
  CCM_ANALOG_VPU_PLL_CFG0 |=
    CCM_ANALOG_VPU_PLL_CFG0_PLL_BYPASS_MASK |
    CCM_ANALOG_VPU_PLL_CFG0_PLL_CLKE_MASK |
    CCM_ANALOG_VPU_PLL_CFG0_PLL_REFCLK_SEL(0b00) |
    CCM_ANALOG_VPU_PLL_CFG0_PLL_LOCK_SEL_MASK |
    CCM_ANALOG_VPU_PLL_CFG0_PLL_NEWDIV_VAL_MASK |
    CCM_ANALOG_VPU_PLL_CFG0_PLL_REFCLK_DIV_VAL(4) |
    CCM_ANALOG_VPU_PLL_CFG0_PLL_OUTPUT_DIV_VAL(1);

  // Clear bypass the VPU PLL clock
  CCM_ANALOG_VPU_PLL_CFG0 &= ~(CCM_ANALOG_VPU_PLL_CFG0_PLL_BYPASS_MASK);
  // Wait for VPU PLL is locked
  for (count = 0; count < 100; ++count) {
    if (CCM_ANALOG_VPU_PLL_CFG0 & CCM_ANALOG_VPU_PLL_CFG0_PLL_LOCK_MASK) {
      break;
    }
    MicroSecondDelay (10);
  }
  // Check if lock succeeded
  if (!(CCM_ANALOG_VPU_PLL_CFG0 & CCM_ANALOG_VPU_PLL_CFG0_PLL_LOCK_MASK)) {
    DebugPrint (0xFFFFFFFF, "Time out waiting for VPU_PLL to lock\n");
  }

  // Clear PLL new fraction divide input control
  CCM_ANALOG_VPU_PLL_CFG0 &= ~(CCM_ANALOG_VPU_PLL_CFG0_PLL_NEWDIV_VAL_MASK);
  return;
}

/**
  Initialize VPU block.
**/
VOID VpuInit()
{
  ARM_SMC_ARGS smc_args;

  VpuPllInit();

  // Disable VPU_DEC clock root
  CCM_CCGR_VPU_DEC = 0x00;
  // Disable VA53 clock root
  CCM_CCGR_VA53 = 0x00;
  // Disable VP9 clock root
  CCM_CCGR_VP9 = 0x00;

  // Disable VPU BUS power domain
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_VPU_BUS, 0x00, 0x00, smc_args);
  ArmCallSmc(&smc_args);

  // Configure VPU_BUS input clock to 800MHz (SYSTEM_PLL1)
  CCM_TARGET_ROOT_VPU_BUS = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
  // Configure VPU_G1 input clock to 600MHz (VPU_PLL)
  CCM_TARGET_ROOT_VPU_G1 = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
  // Configure VPU_G2 input clock to 600MHz (VPU_PLL)
  CCM_TARGET_ROOT_VPU_G2 = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;

  // Enable VPU_DEC clock root
  CCM_CCGR_VPU_DEC = 0x03;
  // Enable VA53 clock root
  CCM_CCGR_VA53 = 0x03;
  // Enable VP9 clock root
  CCM_CCGR_VP9 = 0x03;

  // Enable VPU BUS power domain
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_VPU_BUS, 0x01, 0x00, smc_args);
  ArmCallSmc(&smc_args);

  // VPUMIX G1/G2 soft reset control
  *((volatile UINT32 *)(IMX_VPU_BLK_CTL_BASE + 0x00)) = 0x03;
  // VPUMIX G1/G2 block clock enable
  *((volatile UINT32 *)(IMX_VPU_BLK_CTL_BASE + 0x04)) = 0x03;
  // G1 fuse decoder enable
  *((volatile UINT32 *)(IMX_VPU_BLK_CTL_BASE + 0x08)) = 0xFFFFFFFF;
  // G1 fuse pp enable
  *((volatile UINT32 *)(IMX_VPU_BLK_CTL_BASE + 0x0C)) = 0xFFFFFFFF;
  // G2 fuse decoder enable
  *((volatile UINT32 *)(IMX_VPU_BLK_CTL_BASE + 0x10)) = 0xFFFFFFFF;
}

/**
  Initialize GPU block.
**/
VOID GpuInit()
{
  ARM_SMC_ARGS smc_args;

  // Disable GPU clock root
  CCM_CCGR_GPU = 0x00;

  // Disable GPU BUS power domain
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_GPU_BUS, 0x00, 0x00, smc_args);
  ArmCallSmc(&smc_args);

  // Configure GPU_CORE input clock to 800MHz (SYSTEM_PLL1)
  CCM_TARGET_ROOT_GPU_CORE = CCM_TARGET_ROOT_MUX(2) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
  // Configure GPU_SHADER input clock to 1000MHz (SYSTEM_PLL2)
  CCM_TARGET_ROOT_GPU_SHADER = CCM_TARGET_ROOT_MUX(4) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
  // Configure GPU_AXI input clock to 800MHz (SYSTEM_PLL1)
  CCM_TARGET_ROOT_GPU_AXI = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
  // Configure GPU_AHB input clock to 400MHz (SYSTEM_PLL1/2)
  CCM_TARGET_ROOT_GPU_AHB = CCM_TARGET_ROOT_MUX(1) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_POST_PODF(1) | CCM_TARGET_ROOT_ENABLE_MASK;

  // Enable GPU clock root
  CCM_CCGR_GPU = 0x03;

  // Enable GPU BUS power domain
  imx_fill_sip(IMX_SIP_GPC, IMX_SIP_CONFIG_GPC_PM_DOMAIN, IMX_GPU_BUS, 0x01, 0x00, smc_args);
  ArmCallSmc(&smc_args);
}

/**
  Initialize USDHC blocks and perform required pin-muxing.
**/
VOID UsdhcInit()
{
  // USDHC1
  // SYSTEM_PLL1_DIV2 = 400MHz
  CCM_TARGET_ROOT_USDHC1 = CCM_TARGET_ROOT_MUX(0x01) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
  // USDHC2
  // SYSTEM_PLL1_DIV2 = 400MHz
  CCM_TARGET_ROOT_USDHC2 = CCM_TARGET_ROOT_MUX(0x01) | CCM_TARGET_ROOT_POST_PODF(0) | CCM_TARGET_ROOT_PRE_PODF(0) | CCM_TARGET_ROOT_ENABLE_MASK;
}

#define ARM_PLL_REF_CLK                         25000000UL

#define IMX_OCOTP_TESTER3_SPEED_SHIFT           8
#define IMX_OCOTP_TESTER3_SPEED_MASK            (0x03 << IMX_OCOTP_TESTER3_SPEED_SHIFT)

#define IMX_OCOTP_TESTER3_800MHZ_SPEED          0
#define IMX_OCOTP_TESTER3_1000MHZ_SPEED         1
#define IMX_OCOTP_TESTER3_1300MHZ_SPEED         2
#define IMX_OCOTP_TESTER3_1500MHZ_SPEED         3

/**
  Initialize MCUs clock speed and power.
**/
VOID McuClkPwrInit()
{
  UINT32        val, pll_freq_hz = 0, mcu_core_voltage;
  UINT32        ref_clk, int_div;
  UINT64        frac_div;

  val = (OCOTP_HW_OCOTP_TESTER3 & IMX_OCOTP_TESTER3_SPEED_MASK) >> IMX_OCOTP_TESTER3_SPEED_SHIFT;
  switch (val) {
    case IMX_OCOTP_TESTER3_800MHZ_SPEED:
      pll_freq_hz = 800000000;
      mcu_core_voltage = 900;
    break;
    case IMX_OCOTP_TESTER3_1000MHZ_SPEED:
      pll_freq_hz = 1000000000;
      mcu_core_voltage = 900;
    break;
    case IMX_OCOTP_TESTER3_1300MHZ_SPEED:
      pll_freq_hz = 1300000000;
      mcu_core_voltage = 1000;
    break;
    case IMX_OCOTP_TESTER3_1500MHZ_SPEED:
      pll_freq_hz = 1500000000;
      mcu_core_voltage = 1000;
    break;
  }
  if (pll_freq_hz != 0) {
    DebugPrint (DEBUG_INFO, "Configure Cortex-A53 cores speed to %dMHz, %dmV\n", pll_freq_hz, mcu_core_voltage);
    ref_clk = (ARM_PLL_REF_CLK / (((CCM_ANALOG_ARM_PLL_CFG0 & CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_MASK) >>
              CCM_ANALOG_ARM_PLL_CFG0_PLL_REFCLK_DIV_VAL_SHIFT) + 1)) * 8;

    pll_freq_hz *= 2;
    int_div = pll_freq_hz / ref_clk;
    frac_div = (UINT64)(pll_freq_hz - int_div * ref_clk) * (1UL << 24);
    frac_div /= ref_clk;

    /* Bypass CCM A53 root, use ARM_PLL -> MUX -> cores A53 */
    CCM_TARGET_ROOT_CORE_SEL_CFG = CCM_TARGET_ROOT_MUX(0x01);

    CCM_ANALOG_ARM_PLL_CFG1 = (CCM_ANALOG_ARM_PLL_CFG1 & ~(CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL_MASK |
                              CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL_MASK)) |
                              (CCM_ANALOG_ARM_PLL_CFG1_PLL_FRAC_DIV_CTL((UINT32)frac_div) |
                              CCM_ANALOG_ARM_PLL_CFG1_PLL_INT_DIV_CTL(int_div - 1));
    CCM_ANALOG_ARM_PLL_CFG0 &= ~(CCM_ANALOG_ARM_PLL_CFG0_PLL_OUTPUT_DIV_VAL_MASK);
    /* Reload FracDivCtl & IntDivClt values */
    CCM_ANALOG_ARM_PLL_CFG0 |= CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_VAL_MASK;
    /* Wait for PLL ACK for new configuration */
    while (CCM_ANALOG_ARM_PLL_CFG0 & CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_ACK_MASK) {}
    CCM_ANALOG_ARM_PLL_CFG0 &= ~(CCM_ANALOG_ARM_PLL_CFG0_PLL_NEWDIV_VAL_MASK);
    /* Configure cores power supply */
    /* Configure GPIO1_IO13 as GPIO to control PWM_LED PAD */
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO13 = IOMUXC_MUX_ALT0;
    if (mcu_core_voltage == 1000) {
      GPIO1_DR &= ~(0x01 << 13);                        /* Set the pad to the low level */
    } else {
      GPIO1_DR |= (0x01 << 13);                         /* Set the pad to the high level */
    }
    GPIO1_GDIR |= (0x01 << 13);                   /* Set output direction */
  }
}

/**
  Initialize controllers that must setup at the early stage
**/
RETURN_STATUS ArmPlatformInitialize(IN UINTN MpId)
{
  if (!ArmPlatformIsPrimaryCore(MpId)) {
    return RETURN_SUCCESS;
  }
  // Initialize debug serial port
  SerialPortInitialize();
  SerialPortWrite((UINT8 *)SERIAL_DEBUG_PORT_INIT_MSG, (UINTN)sizeof(SERIAL_DEBUG_PORT_INIT_MSG));

  // Initialize peripherals
  ImxUngateActiveClock();
  McuClkPwrInit();
  AudioInit();
  I2cInit();
  EnetInit();
#if (FixedPcdGet32(PcdPcie1Enable) || FixedPcdGet32(PcdPcie2Enable))
  PcieInit ();
#endif
  USBInit();
  PwmInit();
  VpuInit();
  GpuInit();
  UsdhcInit();

  return RETURN_SUCCESS;
}

/**
  Return the current Boot Mode
  This function returns the boot reason on the platform
**/
EFI_BOOT_MODE ArmPlatformGetBootMode (VOID)
{
  return BOOT_WITH_FULL_CONFIGURATION;
}

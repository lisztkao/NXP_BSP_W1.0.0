/** @file
*
*  Copyright (c) 2019 Microsoft Corporation. All rights reserved.
*  Copyright (c) Intel Corporation
*  Copyright (c) Apple
*  Copyright (c) ARM Ltd.
*  Copyright (c) Freescale
*  Copyright 2019 - 2020 NXP
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

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/TimerLib.h>
#include "Lcdif.h"

#define LCDIF_VSYNC_EDGE_IRQ_TIMEOUT 35000U

/**
  Reset LCDIF block.
**/
VOID
LcdifReset (
    VOID   
    )
{
    int loop = 0;

    /*
     * To ensure smooth reset/start sequence, wait 35ms(30FPS is considered as minimal frame rate)
     * to complete previous LCDIF operation before reseting of the controller.
     */
    LCDIF_CTRL1_CLR = LCDIF_CTRL1_VSYNC_EDGE_IRQ_MASK;
    while(!(LCDIF_CTRL1 & LCDIF_CTRL1_VSYNC_EDGE_IRQ_MASK)) {
        if(loop >= LCDIF_VSYNC_EDGE_IRQ_TIMEOUT) {
            DEBUG ((DEBUG_ERROR, "VSYNC not received\n"));
            break;
        }
        MicroSecondDelay(1);
        loop++;
    }

    /* LCDIF reset */
    LCDIF_CTRL_CLR = LCDIF_CTRL_SFTRST_MASK;
    while(LCDIF_CTRL & LCDIF_CTRL_SFTRST_MASK);

    LCDIF_CTRL_CLR = LCDIF_CTRL_CLKGATE_MASK;
    while(LCDIF_CTRL & LCDIF_CTRL_CLKGATE_MASK);

    LCDIF_CTRL_SET = LCDIF_CTRL_SFTRST_MASK;
    while(!(LCDIF_CTRL & LCDIF_CTRL_CLKGATE_MASK));

    LCDIF_CTRL_CLR = LCDIF_CTRL_SFTRST_MASK;
    while(LCDIF_CTRL & LCDIF_CTRL_SFTRST_MASK);

    LCDIF_CTRL_CLR = LCDIF_CTRL_CLKGATE_MASK;
    while(LCDIF_CTRL & LCDIF_CTRL_CLKGATE_MASK);
}

/**
  LCDIF enable/disable.

  @param enable Enable/Disable bool flag.
**/
EFI_STATUS
LcdifEnable (
    bool Enable
    )
{
    uint32_t loop = 1000U;
    EFI_STATUS status = EFI_SUCCESS;

    if (Enable) {
        /* Enable LCDIF */
        LCDIF_CTRL_SET = LCDIF_CTRL_RUN_MASK;
    } else {
        LCDIF_CTRL_CLR = LCDIF_CTRL_RUN_MASK;
        while(LCDIF_CTRL & LCDIF_CTRL_RUN_MASK) {
            MicroSecondDelay(1);
            loop--;
            if (!loop) {
                status = EFI_DEVICE_ERROR;
                DEBUG ((DEBUG_ERROR, "LCDIF disable failed\n"));
            }
        }
    }
    return status;
}

/**
  Basic LCDIF init not related to the timing mode.

  @param FrameBuffer Physical address of the SW framebuffer.
**/
VOID
LcdifInit (
    uintptr_t FrameBuffer
    )
{
    /* CTRL reg */
    LCDIF_CTRL = (LCDIF_CTRL_MASTER_MASK |                                               /* Set LCDIF as bus master */
                  LCDIF_CTRL_INPUT_DATA_SWIZZLE(0U) |  LCDIF_CTRL_CSC_DATA_SWIZZLE(0U)); /* No swap, little endian */

    /* CTRL1 reg */
    LCDIF_CTRL1 = LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_MASK; /* Recover on underflow */

    /* CTRL2 */
    LCDIF_CTRL2 = (LCDIF_CTRL2_OUTSTANDING_REQS(4U) |                                    /* Max outstanding transactions: REQ_16 */
                   LCDIF_CTRL2_ODD_LINE_PATTERN(0) | LCDIF_CTRL2_EVEN_LINE_PATTERN(0));  /* RGB order */

    /* Set address of the frame buffer */
    LCDIF_CUR_BUF = FrameBuffer;
    LCDIF_NEXT_BUF = FrameBuffer;
    return;
}

/**
  LCDIF configuration into required timing mode.

  @param Timing Pointer to structure containing detailed timing information.
**/
EFI_STATUS
LcdifSetTimingMode (
    IMX_DISPLAY_TIMING* Timing
    )
{
    uint32_t DatabusWidth, WordLength, PackingFormat;

    switch (Timing->Bpp) {
        case 8U:
            DatabusWidth = LCDIF_CTRL_LCD_DATABUS_WIDTH(1U);
            WordLength = LCDIF_CTRL_WORD_LENGTH(1);
            PackingFormat = 0x0FUL;
            break;
        case 16U:
            DatabusWidth = LCDIF_CTRL_LCD_DATABUS_WIDTH(0U);
            WordLength = LCDIF_CTRL_WORD_LENGTH(0);
            PackingFormat = 0x0FUL;
            break;
        case 18U:
            DatabusWidth = LCDIF_CTRL_LCD_DATABUS_WIDTH(2U);
            WordLength = LCDIF_CTRL_WORD_LENGTH(2);
            PackingFormat = 0x07UL;
            break;
        case 24U:
            DatabusWidth = LCDIF_CTRL_LCD_DATABUS_WIDTH(3U);
            WordLength = LCDIF_CTRL_WORD_LENGTH(3);
            PackingFormat = 0x07UL;
            break;
        default:
            DEBUG ((DEBUG_ERROR, "LcdifSetTimingMode - Unsupported bits per pixel value: %d \n", Timing->Bpp));
            return EFI_DEVICE_ERROR;
    }

    LCDIF_CTRL_SET = LCDIF_CTRL_BYPASS_COUNT_MASK | LCDIF_CTRL_DOTCLK_MODE_MASK |
                    DatabusWidth | WordLength;

    LCDIF_CTRL1_SET = LCDIF_CTRL1_BYTE_PACKING_FORMAT(PackingFormat);

    /* Vertical and Horizontal valid data count */
    LCDIF_TRANSFER_COUNT = ((Timing->VActive << LCDIF_TRANSFER_COUNT_V_COUNT_SHIFT) | Timing->HActive);


    LCDIF_VDCTRL0 = (LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_MASK |
                    LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_MASK |
                    LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_MASK |
                    Timing->VSync);


    LCDIF_VDCTRL1 =  (Timing->VActive + Timing->VBlank);

    LCDIF_VDCTRL2 =  ((Timing->HSync << LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_SHIFT) |
                     (Timing->HActive + Timing->HBlank));

    LCDIF_VDCTRL3 = (((Timing->HBlank - Timing->HSyncOffset) << LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_SHIFT) |
                    (Timing->VBlank - Timing->VSyncOffset));

    LCDIF_VDCTRL4 = (Timing->HActive | LCDIF_VDCTRL4_SYNC_SIGNALS_ON_MASK);

    /* Clear FIFO */
    LCDIF_CTRL1_SET = LCDIF_CTRL1_FIFO_CLEAR_MASK;
    LCDIF_CTRL1_CLR = LCDIF_CTRL1_FIFO_CLEAR_MASK;

    return EFI_SUCCESS;
}

/**
  Dump LCDIF registers.
**/
VOID
LcdifDump (
    VOID
    )
{
    DEBUG ((DEBUG_INFO, "------------------------LCDIF------------------------\n"));
    DEBUG ((DEBUG_INFO, "LCDIF_CTRL           = 0x%08X\n", LCDIF_CTRL));
    DEBUG ((DEBUG_INFO, "LCDIF_CTRL1          = 0x%08X\n", LCDIF_CTRL1));
    DEBUG ((DEBUG_INFO, "LCDIF_CTRL2          = 0x%08X\n", LCDIF_CTRL2));
    DEBUG ((DEBUG_INFO, "LCDIF_TRANSFER_COUNT = 0x%08X\n", LCDIF_TRANSFER_COUNT));
    DEBUG ((DEBUG_INFO, "LCDIF_CUR_BUF        = 0x%08X\n", LCDIF_CUR_BUF));
    DEBUG ((DEBUG_INFO, "LCDIF_NEXT_BUF       = 0x%08X\n", LCDIF_NEXT_BUF));
    DEBUG ((DEBUG_INFO, "LCDIF_TIMING         = 0x%08X\n", LCDIF_TIMING));
    DEBUG ((DEBUG_INFO, "LCDIF_VDCTRL0        = 0x%08X\n", LCDIF_VDCTRL0));
    DEBUG ((DEBUG_INFO, "LCDIF_VDCTRL1        = 0x%08X\n", LCDIF_VDCTRL1));
    DEBUG ((DEBUG_INFO, "LCDIF_VDCTRL2        = 0x%08X\n", LCDIF_VDCTRL2));
    DEBUG ((DEBUG_INFO, "LCDIF_VDCTRL3        = 0x%08X\n", LCDIF_VDCTRL3));
    DEBUG ((DEBUG_INFO, "LCDIF_VDCTRL4        = 0x%08X\n", LCDIF_VDCTRL4));
    DEBUG ((DEBUG_INFO, "LCDIF_DVICTRL0       = 0x%08X\n", LCDIF_DVICTRL0));
    DEBUG ((DEBUG_INFO, "LCDIF_DVICTRL1       = 0x%08X\n", LCDIF_DVICTRL1));
    DEBUG ((DEBUG_INFO, "LCDIF_DVICTRL2       = 0x%08X\n", LCDIF_DVICTRL2));
    DEBUG ((DEBUG_INFO, "LCDIF_DVICTRL3       = 0x%08X\n", LCDIF_DVICTRL3));
    DEBUG ((DEBUG_INFO, "LCDIF_DVICTRL4       = 0x%08X\n", LCDIF_DVICTRL4));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_COEFF0     = 0x%08X\n", LCDIF_CSC_COEFF0));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_COEFF1     = 0x%08X\n", LCDIF_CSC_COEFF1));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_COEFF2     = 0x%08X\n", LCDIF_CSC_COEFF2));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_COEFF3     = 0x%08X\n", LCDIF_CSC_COEFF3));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_COEFF4     = 0x%08X\n", LCDIF_CSC_COEFF4));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_OFFSET     = 0x%08X\n", LCDIF_CSC_OFFSET));
    DEBUG ((DEBUG_INFO, "LCDIF_CSC_LIMIT      = 0x%08X\n", LCDIF_CSC_LIMIT));
    DEBUG ((DEBUG_INFO, "LCDIF_DATA           = 0x%08X\n", LCDIF_DATA));
    DEBUG ((DEBUG_INFO, "LCDIF_BM_ERROR_STAT  = 0x%08X\n", LCDIF_BM_ERROR_STAT));
    DEBUG ((DEBUG_INFO, "LCDIF_CRC_STAT       = 0x%08X\n", LCDIF_CRC_STAT));
    DEBUG ((DEBUG_INFO, "LCDIF_STAT           = 0x%08X\n", LCDIF_STAT));
    DEBUG ((DEBUG_INFO, "LCDIF_THRES          = 0x%08X\n", LCDIF_THRES));
    DEBUG ((DEBUG_INFO, "LCDIF_AS_CTRL        = 0x%08X\n", LCDIF_AS_CTRL));
    DEBUG ((DEBUG_INFO, "LCDIF_AS_BUF         = 0x%08X\n", LCDIF_AS_BUF));
    DEBUG ((DEBUG_INFO, "LCDIF_AS_NEXT_BUF    = 0x%08X\n", LCDIF_AS_NEXT_BUF));
    DEBUG ((DEBUG_INFO, "LCDIF_AS_CLRKEYLOW   = 0x%08X\n", LCDIF_AS_CLRKEYLOW));
    DEBUG ((DEBUG_INFO, "LCDIF_AS_CLRKEYHIGH  = 0x%08X\n", LCDIF_AS_CLRKEYHIGH));
    DEBUG ((DEBUG_INFO, "LCDIF_SYNC_DELAY     = 0x%08X\n", LCDIF_SYNC_DELAY));

    for (uint8_t idx = 0U; idx < 12U; idx++) {
        DEBUG ((DEBUG_INFO, "LCDIF_PIGEON_%d_0 = 0x%08X\n", idx, LCDIF_PIGEON_n_0(idx)));
        DEBUG ((DEBUG_INFO, "LCDIF_PIGEON_%d_1 = 0x%08X\n", idx, LCDIF_PIGEON_n_1(idx)));
        DEBUG ((DEBUG_INFO, "LCDIF_PIGEON_%d_2 = 0x%08X\n", idx, LCDIF_PIGEON_n_2(idx)));
    }
    DEBUG ((DEBUG_INFO, "-----------------------------------------------------\n"));
}

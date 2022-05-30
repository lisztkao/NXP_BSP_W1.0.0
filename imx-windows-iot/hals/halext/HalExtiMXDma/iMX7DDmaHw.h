/* Copyright (c) Microsoft Corporation. All rights reserved.
   Copyright 2019 NXP
   Licensed under the MIT License.

Module Name:

    iMX7DDmaHw.h

Abstract:

    This file includes the types/enums definitions associated with the
    i.MX87D SDMA controller configuration.

Environment:

    Kernel mode only.

Revision History:

*/

#ifndef _IMX7D_SDMA_HW_H
#define _IMX7D_SDMA_HW_H

//
// ----------------------------------------------------------- Type Definitions
//


//
// IMX7D SDMA event definitions.
// These values match the datasheet.
//
typedef enum _IMX7D_SDMA1_EVENT_ID {
    IMX7D_SDMA1_EVENT_ECSPI1_RX = 0,
    IMX7D_SDMA1_EVENT_ECSPI1_TX = 1,
    IMX7D_SDMA1_EVENT_ECSPI2_RX = 2,
    IMX7D_SDMA1_EVENT_ECSPI2_TX = 3,
    IMX7D_SDMA1_EVENT_ECSPI3_RX = 4,
    IMX7D_SDMA1_EVENT_ECSPI3_TX = 5,
    IMX7D_SDMA1_EVENT_ECSPI4_RX = 6,
    IMX7D_SDMA1_EVENT_ECSPI4_TX = 7,
    IMX7D_SDMA1_EVENT_SAI1_RX   = 8,
    IMX7D_SDMA1_EVENT_SAI1_TX   = 9,
    IMX7D_SDMA1_EVENT_SAI2_RX   = 10,
    IMX7D_SDMA1_EVENT_SAI2_TX   = 11,
    IMX7D_SDMA1_EVENT_SAI3_RX   = 12,
    IMX7D_SDMA1_EVENT_SAI3_TX   = 13,
    IMX7D_SDMA1_EVENT_IOMUX_1   = 14,
    IMX7D_SDMA1_EVENT_IOMUX_2   = 15,
    IMX7D_SDMA1_EVENT_ADC1      = 16,
    IMX7D_SDMA1_EVENT_ADC2      = 17,
    IMX7D_SDMA1_EVENT_I2C1_SIM1 = 18,
    IMX7D_SDMA1_EVENT_I2C2_SIM1 = 19,
    IMX7D_SDMA1_EVENT_I2C3_SIM2 = 20,
    IMX7D_SDMA1_EVENT_I2C4_SIM2 = 21,
    IMX7D_SDMA1_EVENT_UART1_RX  = 22,
    IMX7D_SDMA1_EVENT_UART1_TX  = 23,
    IMX7D_SDMA1_EVENT_UART2_RX  = 24,
    IMX7D_SDMA1_EVENT_UART2_TX  = 25,
    IMX7D_SDMA1_EVENT_UART3_RX  = 26,
    IMX7D_SDMA1_EVENT_UART3_TX  = 27,
    IMX7D_SDMA1_EVENT_UART4_RX  = 28,
    IMX7D_SDMA1_EVENT_UART4_TX  = 29,
    IMX7D_SDMA1_EVENT_UART5_RX  = 30,
    IMX7D_SDMA1_EVENT_UART5_TX  = 31,
    IMX7D_SDMA1_EVENT_UART6_RX  = 32,
    IMX7D_SDMA1_EVENT_UART6_TX  = 33,
    IMX7D_SDMA1_EVENT_UART7_RX  = 34,
    IMX7D_SDMA1_EVENT_UART7_TX  = 35,
    IMX7D_SDMA1_EVENT_QSPI1_TX  = 36,
    IMX7D_SDMA1_EVENT_QSPI1_RX  = 37,
    IMX7D_SDMA1_EVENT_GPT1      = 38,
    IMX7D_SDMA1_EVENT_GPT2      = 39,
    IMX7D_SDMA1_EVENT_GPT3_FTM1 = 40,
    IMX7D_SDMA1_EVENT_GPT4_FTM2 = 41,
    IMX7D_SDMA1_EVENT_PXP       = 42,
    IMX7D_SDMA1_EVENT_CSI       = 43,
    IMX7D_SDMA1_EVENT_LCDIF     = 44,
    IMX7D_SDMA1_EVENT_ENET1_EV0 = 45,
    IMX7D_SDMA1_EVENT_ENET2_EV1 = 46,
    IMX7D_SDMA1_EVENT_ENET1_ENET2_EV1 = 47,
} IMX7D_SDMA1_EVENT_ID;

#define IMX7D_SDMA1_EVENT_MUX_SEL0_I2C1 0
#define IMX7D_SDMA1_EVENT_MUX_SEL0_SIM1 1

#define IMX7D_SDMA1_EVENT_MUX_SEL1_I2C2 0
#define IMX7D_SDMA1_EVENT_MUX_SEL1_SIM1 1

#define IMX7D_SDMA1_EVENT_MUX_SEL2_I2C3 0
#define IMX7D_SDMA1_EVENT_MUX_SEL2_SIM2 1

#define IMX7D_SDMA1_EVENT_MUX_SEL3_I2C4 0
#define IMX7D_SDMA1_EVENT_MUX_SEL3_SIM2 1

#define IMX7D_SDMA1_EVENT_MUX_SEL4_ENET1_EV1 0
#define IMX7D_SDMA1_EVENT_MUX_SEL4_ENET2_EV1 1

#define IMX7D_SDMA1_EVENT_MUX_SEL5_GPT3 0
#define IMX7D_SDMA1_EVENT_MUX_SEL5_FTM1 1

#define IMX7D_SDMA1_EVENT_MUX_SEL6_GPT4 0
#define IMX7D_SDMA1_EVENT_MUX_SEL6_FTM2 1
//
// -------------------------------------------------------------------- Globals
//

//
// IMX8 Dual DMA request -> Channel configuration
//

SDMA_CHANNEL_CONFIG Imx7dDmaReqToChannelConfig[] = {
    // (0) SDMA_REQ_VPU
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_VPU
    },
    // (1) SDMA_REQ_IPU2
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_IPU2
    },
    // (2) SDMA_REQ_IPU1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_IPU1
    },
    // (3) SDMA_REQ_HDMI_AUDIO
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_HDMI_AUDIO
    },
    // (4) SDMA_REQ_ECSPI1_RX -> Event 0
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_ECSPI1_RX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI1_RX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (5) SDMA_REQ_ECSPI1_TX -> Event 1
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_ECSPI1_TX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI1_TX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (6) SDMA_REQ_ECSPI2_RX -> Event 2
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_ECSPI2_RX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI2_RX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (7) SDMA_REQ_ECSPI2_TX -> Event 3
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_ECSPI2_TX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI2_TX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (8) SDMA_REQ_ECSPI3_RX
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_ECSPI3_RX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI3_RX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (9) SDMA_REQ_ECSPI3_TX
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_ECSPI3_TX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI3_TX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (10) SDMA_REQ_ECSPI4_RX
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_ECSPI4_RX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI4_RX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (11) SDMA_REQ_ECSPI4_TX
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_ECSPI4_TX,             // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ECSPI4_TX,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (12) SDMA_REQ_ECSPI5_RX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ECSPI5_RX
    },
    // (13) SDMA_REQ_ECSPI5_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ECSPI5_TX
    },
    // (14) SDMA_REQ_I2C1_RX -> Event 18
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_I2C1_RX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C1_SIM1,
                DMA_EVENT_MUX_SEL0,
                IMX7D_SDMA1_EVENT_MUX_SEL0_I2C1,
            },
        },
    },
    // (15) SDMA_REQ_I2C1_TX -> Event 18
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_I2C1_TX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C1_SIM1,
                DMA_EVENT_MUX_SEL0,
                IMX7D_SDMA1_EVENT_MUX_SEL0_I2C1,
            },
        },
    },
    // (16) SDMA_REQ_I2C2_RX -> Event 19
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_I2C2_RX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C2_SIM1,
                DMA_EVENT_MUX_SEL1,
                IMX7D_SDMA1_EVENT_MUX_SEL1_I2C2,
            },
        },
    },
    // (17) SDMA_REQ_I2C2_TX -> Event 19
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_I2C2_TX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C2_SIM1,
                DMA_EVENT_MUX_SEL1,
                IMX7D_SDMA1_EVENT_MUX_SEL1_I2C2,
            },
        },
    },
    // (18) SDMA_REQ_I2C3_RX -> Event 20
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_I2C3_RX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C3_SIM2,
                DMA_EVENT_MUX_SEL2,
                IMX7D_SDMA1_EVENT_MUX_SEL2_I2C3,
            },
        },
    },
    // (19) SDMA_REQ_I2C3_TX -> Event 20
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_I2C3_TX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C3_SIM2,
                DMA_EVENT_MUX_SEL2,
                IMX7D_SDMA1_EVENT_MUX_SEL2_I2C3,
            },
        },
    },
    // (20) SDMA_REQ_UART1_RX -> Event 22
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART1_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART1_RX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (21) SDMA_REQ_UART1_TX -> Event 23
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART1_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART1_TX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (22) SDMA_REQ_UART2_RX -> Event 24
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART2_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART2_RX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (23) SDMA_REQ_UART2_TX -> Event 25
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART2_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART2_TX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (24) SDMA_REQ_UART3_RX -> Event 26
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART3_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART3_RX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (25) SDMA_REQ_UART3_TX -> Event 27
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART3_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART3_TX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (26) SDMA_REQ_UART4_RX -> Event 28
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART4_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART4_RX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (27) SDMA_REQ_UART4_TX -> Event 29
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART4_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART4_TX, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (28) SDMA_REQ_UART5_RX -> Event 30
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART5_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART5_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (29) SDMA_REQ_UART5_TX -> Event 31
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART5_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART5_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (30) SDMA_REQ_SPDIF_RX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SPDIF_RX
    },
    // (31) SDMA_REQ_SPDIF_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SPDIF_TX
    },
    // (32) SDMA_REQ_EPIT1 -> Event 0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_EPIT1
    },
    // (33) SDMA_REQ_EPIT2 -> Event 0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_EPIT2
    },
    //
    // Timer SDMA events (GPTx) can be used for triggering any 
    // channel. We configure it for 32bit memory to memory transfers.
    //
    // (34) SDMA_REQ_GPT1 -> Event 38
    {
        imx7_ap_2_ap_ADDR,              // Script address
        SDMA_REQ_GPT1,                  // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width (24 bit)
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        1,                              // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_GPT1, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (35) SDMA_REQ_ASRC_RXA
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_RXA
    },
    // (36) SDMA_REQ_ASRC_RXB
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_RXB
    },
    // (37) SDMA_REQ_ASRC_RXC
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_RXC
    },
    // (38) SDMA_REQ_ASRC_TXA
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_TXA
    },
    // (39) SDMA_REQ_ASRC_TXB
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_TXB
    },
    // (40) SDMA_REQ_ASRC_TXC
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_TXC
    },
    // (41) SDMA_REQ_ESAI_RX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ESAI_RX
    },
    // (42) SDMA_REQ_ESAI_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ESAI_TX
    },
    // (43) SDMA_REQ_ASRC_TXA_2_ESAI_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_TXA_2_ESAI_TX
    },
    // (44) SDMA_REQ_ASRC_TXB_2_ESAI_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_TXB_2_ESAI_TX
    },
    // (45) SDMA_REQ_ASRC_TXC_2_ESAI_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ASRC_TXC_2_ESAI_TX
    },
    // (46) SDMA_REQ_SSI1_RX1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI1_RX1
    },
    // (47) SDMA_REQ_SSI1_TX1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI1_TX1
    },
    // (48) SDMA_REQ_SSI1_RX0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI1_RX0
    },
    // (49) SDMA_REQ_SSI1_TX0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI1_TX0
    },
    // (50) SDMA_REQ_SSI2_RX1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI2_RX1
    },
    // (51) SDMA_REQ_SSI2_TX1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI2_TX1
    },
    // (52) SDMA_REQ_SSI2_RX0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI2_RX0
    },
    // (53) SDMA_REQ_SSI2_TX0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI2_TX0
    },
    // (54) SDMA_REQ_SSI3_RX1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI3_RX1
    },
    // (55) SDMA_REQ_SSI3_TX1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI3_TX1
    },
    // (56) SDMA_REQ_SSI3_RX0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI3_RX0
    },
    // (57) SDMA_REQ_SSI3_TX0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_SSI3_TX0
    },
    // (58) SDMA_REQ_EXT1 -> Map to IMX7D_SDMA1_EVENT_IOMUX_1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_EXT1
    },
    // (59) SDMA_REQ_EXT2 -> Map to IMX7D_SDMA1_EVENT_IOMUX_2
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_EXT2
    },
    // (60) SDMA_REQ_UART6_RX -> Event  32
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART6_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART6_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (61) SDMA_REQ_UART6_TX -> Event 33
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART6_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART6_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (62) SDMA_REQ_ADC1 -> Event 16
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_ADC1,                  // DMA request ID
        DMA_WIDTH_8BIT,
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        1,                              // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ADC1,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (63) SDMA_REQ_ADC2 -> Event 17
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_ADC2,                  // DMA request ID
        DMA_WIDTH_8BIT,
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        1,                              // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_ADC2,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (64) SDMA_REQ_I2C4_RX -> Event 21
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_I2C4_RX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C4_SIM2,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (65) SDMA_REQ_I2C4_TX -> Event 21
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_I2C4_TX,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_I2C4_SIM2,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (66) SDMA_REQ_CSI1 -> Event 43
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_CSI1,                  // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_CSI,
                DMA_EVENT_EXCLUSIVE,
            },
        },
    },
    // (67) SDMA_REQ_CSI2 -> Event 0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_CSI2
    },
    // (68) SDMA_REQ_PXP -> Event 42
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_PXP,               // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_PXP,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (69) SDMA_REQ_LCDIF1 -> Event 44
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_LCDIF1,                // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
          {
            IMX7D_SDMA1_EVENT_LCDIF,
            DMA_EVENT_EXCLUSIVE
          },
        },
    },
    // (70) SDMA_REQ_LCDIF2
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_LCDIF2
    },
    // (71) SDMA_REQ_QSPI1_RX -> Event 37
    {
        imx7_app_2_mcu_ADDR,            // Script address
        SDMA_REQ_QSPI1_RX,              // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_QSPI1_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (72) SDMA_REQ_QSPI1_TX -> Event 36
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_QSPI1_TX,              // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_QSPI1_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (73) SDMA_REQ_QSPI2_RX -> Event 0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_QSPI2_RX
    },
    // (74) SDMA_REQ_QSPI2_TX -> Event 0
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_QSPI2_TX
    },
    // (75) SDMA_REQ_SAI1_TX -> Event 8
    {
        imx7_mcu_2_sai_ADDR,            // Script address
        SDMA_REQ_SAI1_TX,               // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_SAI1_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (76) SDMA_REQ_SAI1_RX -> Event 9
    {
        imx7_sai_2_mcu_ADDR,            // Script address
        SDMA_REQ_SAI1_RX,               // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_SAI1_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (77) SDMA_REQ_SAI2_TX -> Event 11
    {
        imx7_mcu_2_sai_ADDR,            // Script address
        SDMA_REQ_SAI2_TX,               // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_SAI2_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (78) SDMA_REQ_SAI2_RX -> Event 10
    {
        imx7_sai_2_mcu_ADDR,            // Script address
        SDMA_REQ_SAI2_RX,               // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_SAI2_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (79) SDMA_REQ_SAI3_TX -> Event 13
    {
        imx7_mcu_2_sai_ADDR,            // Script address
        SDMA_REQ_SAI3_TX,               // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_TX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_SAI3_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (80) SDMA_REQ_SAI3_RX -> Event 12
    {
        imx7_sai_2_mcu_ADDR,            // Script address
        SDMA_REQ_SAI3_RX,               // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_DEFAULT_RX,        // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_SAI3_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (81) SDMA_REQ_SAI4_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_SAI4_TX,               // DMA request ID
    },
    // (82) SDMA_REQ_SAI4_RX
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_SAI4_RX,               // DMA request ID
    },
    // (83) SDMA_REQ_SAI5_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_SAI5_TX,               // DMA request ID
    },
    // (84) SDMA_REQ_SAI5_RX
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_SAI5_RX,               // DMA request ID
    },
    // (85) SDMA_REQ_SAI6_TX
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_SAI6_TX,               // DMA request ID
    },
    // (86) SDMA_REQ_SAI6_RX
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_SAI6_RX,               // DMA request ID
    },
    // (87) SDMA_REQ_UART7_RX -> Event 34
    {
        imx7_uart_2_mcu_ADDR,           // Script address
        SDMA_REQ_UART7_RX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_RX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART7_RX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (88) SDMA_REQ_UART7_TX -> Event 35
    {
        imx7_mcu_2_app_ADDR,            // Script address
        SDMA_REQ_UART7_TX,              // DMA request ID
        DMA_WIDTH_8BIT,                 // Transfer width
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        IMX_WL_SCALE_UART_TX,           // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_UART7_TX,
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    //
    // Timer SDMA events (GPTx) can be used for triggering any 
    // channel. We configure it for 32bit memory to memory transfers.
    //
    // (89) SDMA_REQ_GPT2 -> Event 39
    {
        imx7_ap_2_ap_ADDR,              // Script address
        SDMA_REQ_GPT2,                  // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width (24 bit)
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        1,                              // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_GPT2, 
                DMA_EVENT_EXCLUSIVE
            },
        },
    },
    // (90) SDMA_REQ_GPT3 -> Event 40
    {
        imx7_ap_2_ap_ADDR,              // Script address
        SDMA_REQ_GPT3,                  // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width (24 bit)
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        1,                              // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_GPT3_FTM1,
                DMA_EVENT_MUX_SEL5,
                IMX7D_SDMA1_EVENT_MUX_SEL5_GPT3,
            },
        },
    },
    // (91) SDMA_REQ_GPT4 -> Event 41
    {
        imx7_ap_2_ap_ADDR,              // Script address
        SDMA_REQ_GPT4,                  // DMA request ID
        DMA_WIDTH_32BIT,                // Transfer width (24 bit)
        0,                              // Owner channel
        SDMA_DEVICE_FLAG_FIXED_ADDRESS, // Flags
        0,                              // Peripheral 2 address
        1,                              // Watermark level scale (percent)
        1,                              // Number of DMA events to follow
        {
            {
                IMX7D_SDMA1_EVENT_GPT4_FTM2,
                DMA_EVENT_MUX_SEL6,
                IMX7D_SDMA1_EVENT_MUX_SEL6_GPT4,
            },
        },
        1,                              // SDMA instance 2
    },
    // (92) SDMA_REQ_GPT5 -> SDMA instance 2 Event 39
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_GPT5,                  // DMA request ID
    },
    // (93) SDMA_REQ_GPT6 -> SDMA instance 2 Event 40
    {
        SDMA_UNSUPPORTED_REQUEST_ID,    // Script address
        SDMA_REQ_GPT6,                  // DMA request ID
    },
    // (94) SDMA_REQ_ENET1_EV0 -> Event 45
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ENET1_EV0
    },
    // (95) SDMA_REQ_ENET1_EV1 -> Event 47
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ENET1_EV1
    },
    // (96) SDMA_REQ_ENET2_EV0 (actually ENET1_EV2) -> Event 44
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ENET2_EV0
    },
    // (97) SDMA_REQ_ENET2_EV1 (actually ENET1_EV3) -> Event 46
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_ENET2_EV1
    },
    // (98) SDMA_REQ_EXT3 -> Map to IMX7D_SDMA2_EVENT_IOMUX_1
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_EXT3
    },
    // (99) SDMA_REQ_EXT4 -> Map to IMX7D_SDMA2_EVENT_IOMUX_2
    {
        SDMA_UNSUPPORTED_REQUEST_ID, // Not supported
        SDMA_REQ_EXT4
    },
};

ULONG Imx7dDmaReqMax = ARRAYSIZE(Imx7dDmaReqToChannelConfig) - 1;

#endif // !_IMX7D_SDMA_HW_H

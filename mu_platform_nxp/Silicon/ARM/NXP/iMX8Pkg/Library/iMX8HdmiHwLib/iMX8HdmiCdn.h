/** @file

  Copyright 2020 NXP

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _IMX8MHDMICDN_H_
#define _IMX8MHDMICDN_H_

#include <stdint.h>
#include <stdbool.h>
#include "iMX8.h"

#define HDMI_CDN_IMX8M_REGISTERS_LENGTH         0x100000

// HDMI cadence OpCodes
#define IMX_HDMICDN_GENERAL_READ_REGISTER       0x07
#define IMX_HDMICDN_GENERAL_WRITE_REGISTER      0x05

// HDMI cadence Module ID
#define IMX_HDMICDN_MB_MODULE_ID_DP_TX          0x01
#define IMX_HDMICDN_MB_MODULE_ID_DP_RX          0x02
#define IMX_HDMICDN_MB_MODULE_ID_HDMI_TX        0x03
#define IMX_HDMICDN_MB_MODULE_ID_HDMI_RX        0x04
#define IMX_HDMICDN_MB_MODULE_ID_MHL_TX         0x05
#define IMX_HDMICDN_MB_MODULE_ID_MHL_RX         0x06
#define IMX_HDMICDN_MB_MODULE_ID_HDCP_TX        0x07
#define IMX_HDMICDN_MB_MODULE_ID_HDCP_RX        0x08
#define IMX_HDMICDN_MB_MODULE_ID_HDCP_GENERAL   0x09
#define IMX_HDMICDN_MB_MODULE_ID_GENERAL        0x0A
#define IMX_HDMICDN_MB_MODULE_ID                1

/* register HDTX_CONTROLLER */
#define IMX_HDMICDN_ADDR_SOURCE_MHL_HD          0x01000
#define IMX_HDMICDN_HDTX_CONTROLLER             0x18
#define IMX_HDMICDN_HDTX_CONTROLLER_F_DATA_EN   (0x01 << 15)

/* APB read/write operation macros */
#define IMX_HDMICDN_APB_WRITE(value)                                     \
    do {                                                                 \
        while (HDMI_TX_MAILBOX_FULL_ADDR &                               \
              HDMI_TX_MAILBOX_FULL_ADDR_mailbox_full_MASK) {}            \
        HDMI_TX_MAILBOX0_WR_DATA = value;                                \
    } while (0)

#define IMX_HDMICDN_APB_READ(value)                                      \
    do {                                                                 \
        while (HDMI_TX_MAILBOX_EMPTY_ADDR &                              \
              HDMI_TX_MAILBOX_EMPTY_ADDR_mailbox_empty_MASK) {}          \
        value = HDMI_TX_MAILBOX0_RD_DATA;                                \
    } while (0)

#define IMX_HDMICDN_APB_READ8(value)                                     \
    do {                                                                 \
        IMX_HDMICDN_APB_READ(value);                                     \
    } while (0)

#define IMX_HDMICDN_APB_READ16(value)                                    \
    do {                                                                 \
        UINT32 rdValue;                                                  \
        IMX_HDMICDN_APB_READ(rdValue);                                   \
        value = (rdValue << 8);                                          \
        IMX_HDMICDN_APB_READ(rdValue);                                   \
        value |= (rdValue << 0);                                         \
    } while (0)

#define IMX_HDMICDN_APB_READ32(value)                                    \
    do {                                                                 \
        UINT32 rdValue;                                                  \
        IMX_HDMICDN_APB_READ(rdValue);                                   \
        value = (rdValue << 24);                                         \
        IMX_HDMICDN_APB_READ(rdValue);                                   \
        value |= (rdValue << 16);                                        \
        IMX_HDMICDN_APB_READ(rdValue);                                   \
        value = (rdValue << 8);                                          \
        IMX_HDMICDN_APB_READ(rdValue);                                   \
        value |= (rdValue << 0);                                         \
    } while (0)

#define IMX_HDMICDN_APB_WRITE8(value)                                    \
    do {                                                                 \
        IMX_HDMICDN_APB_WRITE(value);                                    \
    } while (0)

#define IMX_HDMICDN_APB_WRITE16(value)                                   \
    do {                                                                 \
        IMX_HDMICDN_APB_WRITE((value >> 8) & 0xFF);                      \
        IMX_HDMICDN_APB_WRITE((value >> 0) & 0xFF);                      \
    } while (0)

#define IMX_HDMICDN_APB_WRITE32(value)                                   \
    do {                                                                 \
        IMX_HDMICDN_APB_WRITE((value >> 24) & 0xFF);                     \
        IMX_HDMICDN_APB_WRITE((value >> 16) & 0xFF);                     \
        IMX_HDMICDN_APB_WRITE((value >> 8) & 0xFF);                      \
        IMX_HDMICDN_APB_WRITE((value >> 0) & 0xFF);                      \
    } while (0)

VOID HdmiCdnOn(VOID);
VOID HdmiCdnOff(VOID);

#endif

/** @file

  Copyright 2020 NXP

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/TimerLib.h>

#include "iMX8HdmiCdn.h"

VOID HdmiCdnGeneralReadRegister(UINT32 address, UINT32 *value)
{
    UINT32 value32, respAddress32, length;

    // Read CDN register OpCode
    IMX_HDMICDN_APB_WRITE8(IMX_HDMICDN_GENERAL_READ_REGISTER);
    // Use general module ID
    IMX_HDMICDN_APB_WRITE8(IMX_HDMICDN_MB_MODULE_ID_GENERAL);
    // Length 4
    IMX_HDMICDN_APB_WRITE16(0x0004);
    // Write address
    IMX_HDMICDN_APB_WRITE32(address);
    // Response
    // Operation OpCode
    IMX_HDMICDN_APB_READ(value32);
    if (value32 != IMX_HDMICDN_GENERAL_READ_REGISTER) {
        DEBUG ((DEBUG_ERROR, "Rsponse of OpCode is wrong!\n"));
    }
    // Module ID
    IMX_HDMICDN_APB_READ8(value32);
    if (value32 != IMX_HDMICDN_MB_MODULE_ID_GENERAL) {
        DEBUG ((DEBUG_ERROR, "Module response ID value is wrong!\n"));
    }
    // Length
    IMX_HDMICDN_APB_READ16(length);
    if (length != 8) {
        DEBUG ((DEBUG_ERROR, "esponse length %u is wrong!\n"));
    }
    // Read response address
    IMX_HDMICDN_APB_READ32(respAddress32);
    if (respAddress32 != address) {
        DEBUG ((DEBUG_ERROR, "Module response address value is wrong!\n"));
    }
    // Read response value
    IMX_HDMICDN_APB_READ32(*value);

    DEBUG((DEBUG_INFO, "HDMI cadence read general register, addr 0x%x, val: 0x%x\n", address, *value));
}

VOID HdmiCdnGeneralWriteRegister(UINT32 address, UINT32 value)
{
    DEBUG((DEBUG_INFO, "HDMI cadence write general register, addr 0x%x, val: 0x%x\n", address, value));

    // Read CDN register
    IMX_HDMICDN_APB_WRITE8(IMX_HDMICDN_GENERAL_WRITE_REGISTER);
    IMX_HDMICDN_APB_WRITE8(IMX_HDMICDN_MB_MODULE_ID_GENERAL);
    // Length 8
    IMX_HDMICDN_APB_WRITE16(0x0008);
    // Write address
    IMX_HDMICDN_APB_WRITE32(address);
    // Write value
    IMX_HDMICDN_APB_WRITE32(value);
}


VOID HdmiCdnOn(VOID)
{
    UINT32 value32;

    DEBUG((DEBUG_INFO, "Turning On HDMI cadence \n"));
    HdmiCdnGeneralReadRegister(IMX_HDMICDN_ADDR_SOURCE_MHL_HD + IMX_HDMICDN_HDTX_CONTROLLER,
        &value32);
    value32 |= (IMX_HDMICDN_HDTX_CONTROLLER_F_DATA_EN);  // Enable HDMI
    HdmiCdnGeneralWriteRegister(IMX_HDMICDN_ADDR_SOURCE_MHL_HD + IMX_HDMICDN_HDTX_CONTROLLER,
        value32);
}

VOID HdmiCdnOff(VOID)
{
    UINT32 value32;

    DEBUG((DEBUG_INFO, "Turning Off HDMI cadence \n"));

    HdmiCdnGeneralReadRegister(IMX_HDMICDN_ADDR_SOURCE_MHL_HD + IMX_HDMICDN_HDTX_CONTROLLER,
                               &value32);
    value32 &= ~(IMX_HDMICDN_HDTX_CONTROLLER_F_DATA_EN);  // Disable HDMI
    HdmiCdnGeneralWriteRegister(IMX_HDMICDN_ADDR_SOURCE_MHL_HD + IMX_HDMICDN_HDTX_CONTROLLER,
                               value32);
}

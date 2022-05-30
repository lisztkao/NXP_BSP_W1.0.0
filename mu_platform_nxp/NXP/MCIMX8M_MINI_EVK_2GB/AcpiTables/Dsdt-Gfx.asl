/** @file
*
*  Copyright (c) 2018 Microsoft Corporation. All rights reserved.
*  Copyright 2019 NXP
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

// Description: Graphics Processing Unit (GPU)
Device (GPU0)
{
  Name (_HID, "NXP0200")
  Name (_CID, "NXP0200")
  Name (_UID, 0)

  Method (_STA) {
    Return (0xf)
  }

  Name (_CRS, ResourceTemplate () {
    // MCU and board type information:
    // imx6QP:  0x00010000, SDB: 0x000000001
    // imx6Q:   0x00020000, SDB: 0x000000001, SDP: 0x000000002
    // imx6SX:  0x00030000, SDB: 0x000000001
    // imx6DL:  0x00040000, SDP: 0x000000002
    // imx6UL:  0x00050000, EVK: 0x000000003
    // imx6ULL: 0x00060000, EVK: 0x000000003
    // imx7D:   0x00070000, SABRE: 0x000000004
    // imx8MM   0x00080000, EVK: 0x000000003
    // imx8MQ   0x00090000, EVK: 0x000000003
    MEMORY32FIXED (ReadWrite, 0x00080003, 0xAAAA, )

    // MCU device information:
    //   LCDIF:    0xDEF00001
    //   IPU Base: 0xDEF00002
    //   HDMI PHY: 0xDEF00003
    //   GPU 3D:   0xDEF00004
    //   GPU 2D:   0xDEF00005
    //   HDMI_CDN  0xDEF00006
    //   MIPI_DSI  0xDEF00007

    // MIPI_DSI information:
    MEMORY32FIXED (ReadWrite, 0xDEF00007, 0xAAAA, )
    MEMORY32FIXED (ReadWrite, 0x32E10000, 0x10000, )
  })
}

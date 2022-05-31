/** @file
*
*  Copyright (c) Microsoft Corporation. All rights reserved.
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

Device (GPU1)
{
  Name (_HID, "VERI7000")
  Name (_CID, "VERI7000")
  Name (_UID, 0)

  Method (_STA)
  {
    Return (0xF)
  }

  Name (_CRS, ResourceTemplate () {
    // GPU REG
    MEMORY32FIXED( ReadWrite, 0x38000000, 0x10000, )
    // DCSS REG
    MEMORY32FIXED( ReadWrite, 0x32e00000, 0x30000, )
    // HDMI REG
    MEMORY32FIXED( ReadWrite, 0x32c00000, 0x100000, )
    // HDMI SEC REG
    MEMORY32FIXED( ReadWrite, 0x32e40000, 0x40000, )
    // HDMI RESET REG
    MEMORY32FIXED( ReadWrite, 0x32e2f000, 0x10, )
    // GPU interrupt
    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 35 }
    // DCSS irq steer
    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 50 }
    // HDMI plug_in interrupt
    // Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 48 }
    // HDMI plug_out interrupt
    // Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 57 }
  })
}

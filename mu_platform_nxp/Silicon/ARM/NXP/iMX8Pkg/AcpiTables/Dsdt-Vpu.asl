/** @file
*  Description: i.MX8M VPU Encoder/Decoder
*
*  Copyright (c) 2019 Microsoft Corporation. All rights reserved.
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

Device (VPU0)
{
  Name (_HID, "NXP0109")
  Name (_UID, 0x0)

  Method (_STA) {
    Return (0xf)
  }

  Name (_CRS, ResourceTemplate () {
    MEMORY32FIXED (ReadWrite, 0x38300000, 0x1FFFFF, )

    // VPU G1 decoder interrupt
    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 39 }

    // VPU G2 decoder interrupt
    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 40 }

    // VPU H1 encoder interrupt
    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 62 }
  })
}

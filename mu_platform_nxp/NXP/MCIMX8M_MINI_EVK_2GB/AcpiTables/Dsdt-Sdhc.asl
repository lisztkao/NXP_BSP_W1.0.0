/*
* Ultra Secured Digital Host Controllers (uSDHC)
*
*  Copyright (c) Microsoft Corporation. All rights reserved.
*  Copyright 2022 NXP
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*/

//
// uSDHC1 - SDIO
//
Device (SDH1)
{
   Name (_HID, "NXP0108")
   Name (_UID, 0x1)
   Name (_CCA, 0x0)    // SDHC is not coherent

   Method (_STA) // State
   {
       Return(0x0) // Disabled
   }

   Method (_CRS, 0x0, NotSerialized) {
       Name (RBUF, ResourceTemplate () {
           MEMORY32FIXED(ReadWrite, 0x30B40000, 0x4000, )
           Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 54 }
       })
       Return(RBUF)
   }

   //
   // Child node to represent the only SD/MMC slot on this SD/MMC bus
   // In theory an SDHC can be connected to multiple SD/MMC slots at
   // the same time, but only 1 device will be selected and active at
   // a time
   //
   Device (SD0)
   {
       Method (_ADR) // Address
       {
         Return (0) // SD/MMC Slot 0
       }

       Method (_RMV) // Remove
       {
         Return (0) // Fixed
       }
   }
}

//
// uSDHC2 - uSD
//
Device (SDH2)
{
   Name (_HID, "NXP0108")
   Name (_UID, 0x2)
   Name (_CCA, 0x0)    // SDHC is not coherent

   Method (_STA)
   {
       Return(0xf)
   }

   Method (_CRS, 0x0, NotSerialized) {
       Name (RBUF, ResourceTemplate () {
           MEMORY32FIXED(ReadWrite, 0x30B50000, 0x4000, )
           Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 55 }
           // CD pin - GPIO1_IO15 - 0 * 32 + 15
           GpioIO(Shared, PullUp, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 15 }
           GpioInt(Edge, ActiveBoth, Shared, PullUp, 0, "\\_SB.GPIO",) { 15 }
       })
       Return(RBUF)
   }

   //
   // Child node to represent the only SD/MMC slot on this SD/MMC bus
   // In theory an SDHC can be connected to multiple SD/MMC slots at
   // the same time, but only 1 device will be selected and active at
   // a time
   //
   Device (SD0)
   {
       Method (_ADR) // Address
       {
         Return (0) // SD/MMC Slot 0
       }

       Method (_RMV) // Remove
       {
         Return (0) // Fixed
       }
   }

   Name (_DSD, Package () {
     ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
       Package () {
         Package (2) {"RegisterBasePA", 0x30B50000},
         Package (2) {"BaseClockFrequencyHz", 400000000},
         Package (2) {"Regulator1V8Exist", 0}
       }
   })
}

//
// uSDHC3 - eMMC
//
Device (SDH3)
{
   Name (_HID, "NXP0108")
   Name (_UID, 0x3)
   Name (_CCA, 0x0)    // SDHC is not coherent

   Method (_STA)
   {
       Return(0xf)
   }

   Method (_CRS, 0x0, NotSerialized) {
       Name (RBUF, ResourceTemplate () {
           MEMORY32FIXED(ReadWrite, 0x30B60000, 0x4000, )
           Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 56 }
       })
       Return(RBUF)
   }

   //
   // Child node to represent the only SD/MMC slot on this SD/MMC bus
   // In theory an SDHC can be connected to multiple SD/MMC slots at
   // the same time, but only 1 device will be selected and active at
   // a time
   //
   Device (SD0)
   {
       Method (_ADR) // Address
       {
         Return (0) // SD/MMC Slot 0
       }

       Method (_RMV) // Remove
       {
         Return (0) // Fixed
       }
   }

   Name (_DSD, Package () {
     ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
       Package () {
         Package (2) {"RegisterBasePA", 0x30B60000},
         Package (2) {"BaseClockFrequencyHz", 400000000},
         Package (2) {"Regulator1V8Exist", 1}
       }
   })
}


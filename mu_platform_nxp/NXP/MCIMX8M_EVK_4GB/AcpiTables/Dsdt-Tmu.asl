/** @file
*
*  Copyright 2020 NXP
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

Device (TC) {
    Name (_HID, "NXP0115")
    Name (_UID, 1)

    Name (_CRS, ResourceTemplate () {
        // CCM_ANALOG base address
        MEMORY32FIXED (ReadWrite, 0x30360000, 0x10000, )

        // PWM_LED (H: 0.9V; L:1.0V) - GPIO1_IO13
        GpioIO (Shared, PullNone, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 13 } // 0 * 32 + 13
    })

    Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
            Package (2) {"ArmPll",
                Package () {
                    Package (2) {"PllType",  "imx8mqFracPll"},
                    Package (2) {"PllRefClock_hz",  25000000},
                    Package (2) {"PllFreqMax_hz", 1600000000},
                    Package (2) {"PllFreqMin_hz",  800000000}
                }
            },
            Package (2) {"CoreOppTable",
                Package () {
                    // Cortex-Ax: freq: Hz , power: uV
                    Package (2) { 800000000,  900000},
                    Package (2) {1000000000,  900000},
                    Package (2) {1300000000, 1000000},
                    Package (2) {1500000000, 1000000}
                }
            }
        }
    })
}

ThermalZone(TZ0) {
    Name (_HID, "NXP010B")
    Name (_UID, 1)
    Name (_PSV, 3480)
    Name (_CRT, 3630)
    Name (_TSP, 30)
    Name (_TC1, 4)
    Name (_TC2, 2)
    Name (_TZD, Package () { \_SB.TC } )
    Name (_HRV, 0x0)

    Method (_STA) {
        Return (0xf)
    }

    Name (_CRS, ResourceTemplate () {
        MEMORY32FIXED (ReadWrite, 0x30260000, 0x10000, )
        Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive) { 81 }
    })

   Name (_DSD, Package () {
    ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package (2) {"range", Package (4) {0xb0000, 0xa0026, 0x80048, 0x70061}},
        Package (2) {"calibration",
          Package () {
            Package (2) {0x00000000, 0x00000023},
            Package (2) {0x00000001, 0x00000029},
            Package (2) {0x00000002, 0x0000002f},
            Package (2) {0x00000003, 0x00000035},
            Package (2) {0x00000004, 0x0000003d},
            Package (2) {0x00000005, 0x00000043},
            Package (2) {0x00000006, 0x0000004b},
            Package (2) {0x00000007, 0x00000051},
            Package (2) {0x00000008, 0x00000057},
            Package (2) {0x00000009, 0x0000005f},
            Package (2) {0x0000000a, 0x00000067},
            Package (2) {0x0000000b, 0x0000006f},

            Package (2) {0x00010000, 0x0000001b},
            Package (2) {0x00010001, 0x00000023},
            Package (2) {0x00010002, 0x0000002b},
            Package (2) {0x00010003, 0x00000033},
            Package (2) {0x00010004, 0x0000003b},
            Package (2) {0x00010005, 0x00000043},
            Package (2) {0x00010006, 0x0000004b},
            Package (2) {0x00010007, 0x00000055},
            Package (2) {0x00010008, 0x0000005d},
            Package (2) {0x00010009, 0x00000067},
            Package (2) {0x0001000a, 0x00000070},

            Package (2) {0x00020000, 0x00000017},
            Package (2) {0x00020001, 0x00000023},
            Package (2) {0x00020002, 0x0000002d},
            Package (2) {0x00020003, 0x00000037},
            Package (2) {0x00020004, 0x00000041},
            Package (2) {0x00020005, 0x0000004b},
            Package (2) {0x00020006, 0x00000057},
            Package (2) {0x00020007, 0x00000063},
            Package (2) {0x00020008, 0x0000006f},

            Package (2) {0x00030000, 0x00000015},
            Package (2) {0x00030001, 0x00000021},
            Package (2) {0x00030002, 0x0000002d},
            Package (2) {0x00030003, 0x00000039},
            Package (2) {0x00030004, 0x00000045},
            Package (2) {0x00030005, 0x00000053},
            Package (2) {0x00030006, 0x0000005f},
            Package (2) {0x00030007, 0x00000071}
          }
      }
    }
  })
}

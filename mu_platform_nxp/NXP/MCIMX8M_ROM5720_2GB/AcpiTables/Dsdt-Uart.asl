/** @file
*
* Description: iMX8M UART
*
*  Copyright (c) 2019, Microsoft Corporation. All rights reserved.
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
Device (UAR1)
{
    Name (_HID, "NXP0113") //NXP0113 for 24MHz UART_CLK_ROOT
    Name (_UID, 0x1)
    Name (_DDN, "UART1")
    Method (_STA)
    {
       Return(0xF)
    }
    Method (_CRS, 0x0, NotSerialized) {
        Name (RBUF, ResourceTemplate () {
            MEMORY32FIXED(ReadWrite, 0x30860000, 0x4000, )
            Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 58 }

            // UART2_RX_DATA - GPIO5_IO22 - 150
            // UART2_TX_DATA - GPIO5_IO23 - 151
            // MsftFunctionConfig (Exclusive, PullUp, IMX_ALT2, "\\_SB.GPIO", 0,
            // ResourceConsumer, ) { 150, 151 }
            //
            // MsftFunctionConfig (Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6) { Pin List }
            VendorLong () {
              MSFT_UUID,            // Vendor UUID (MSFT UUID)
              MSFT_FUNCTION_CONFIG, // Resource Identifier (MSFT Function Config)
              0x1d,0x00,            // Length (0xF + sizeof(PinList) + sizeof(ResourceName))
              0x01,                 // Revision (0x1)
              RESOURCECONSUMER_EXCLUSIVE, // Flags (Arg5 | Arg0: ResourceConsumer | Exclusive)
              PULL_UP,              // Pin configuration (Arg1: PullUp)
              IMX_ALT0,0x00,        // Function Number (Arg2: IMX_ALT0)
              PIN_TABLE_OFFSET,     // Pin Table Offset (0x12)
              0x00,                 // Resource Source Index (Arg4: 0)
              0x16,0x00,            // Resource Source Name Offset (0x12 + sizeof(PinList))
              0x20,0x00,            // Vendor Data Offset (0x12 + sizeof(PinList) + sizeof(ResourceName))
              0x00,0x00,            // Vendor Data Length (sizeof(Arg6) = 0)
              0x96,0x00,0x97,0x00,  // Pin List (150, 151)
              SB_GPIO               // Resource Name (Arg3: \_SB.GPIO in ASCII)
            }

            FixedDMA (SDMA_REQ_UART1_RX, 2, Width8Bit, )
            FixedDMA (SDMA_REQ_UART1_TX, 1, Width8Bit, )

            UARTSerialBus (
            115200,
            DataBitsEight,
            StopBitsOne,
            0,                // LinesInUse
            LittleEndian,
            ParityTypeNone,
            FlowControlNone,
            0,
            0,
            "\\_SB.CPU0",
            0,
            ResourceConsumer,
            ,)
        })
        Return(RBUF)
    }

  Name (_DSD, Package () {
    ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package (2) {"SerCx-FriendlyName", "UART1"}
      }
  })
}

Device (UAR2)
{
    Name (_HID, "NXP0113")
    Name (_UID, 0x2)
    Name (_DDN, "UART2")
    Method (_STA)
    {
       Return(0xF)
    }
    Method (_CRS, 0x0, NotSerialized) {
        Name (RBUF, ResourceTemplate () {
            MEMORY32FIXED(ReadWrite, 0x30890000, 0x4000, )
            Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 59 }

            // UART2_RX_DATA - GPIO5_IO24 - 152
            // UART2_TX_DATA - GPIO5_IO25 - 153
            // MsftFunctionConfig (Exclusive, PullUp, IMX_ALT0, "\\_SB.GPIO", 0,
            // ResourceConsumer, ) { 152, 153 }
            //
            // MsftFunctionConfig (Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6) { Pin List }
            VendorLong () {
              MSFT_UUID,            // Vendor UUID (MSFT UUID)
              MSFT_FUNCTION_CONFIG, // Resource Identifier (MSFT Function Config)
              0x1d,0x00,            // Length (0xF + sizeof(PinList) + sizeof(ResourceName))
              0x01,                 // Revision (0x1)
              RESOURCECONSUMER_EXCLUSIVE, // Flags (Arg5 | Arg0: ResourceConsumer | Exclusive)
              PULL_UP,              // Pin configuration (Arg1: PullUp)
              IMX_ALT0,0x00,        // Function Number (Arg2: IMX_ALT0)
              PIN_TABLE_OFFSET,     // Pin Table Offset (0x12)
              0x00,                 // Resource Source Index (Arg4: 0)
              0x16,0x00,            // Resource Source Name Offset (0x12 + sizeof(PinList))
              0x20,0x00,            // Vendor Data Offset (0x12 + sizeof(PinList) + sizeof(ResourceName))
              0x00,0x00,            // Vendor Data Length (sizeof(Arg6) = 0)
              0x98,0x00,0x99,0x00,  // Pin List (152, 153)
              SB_GPIO               // Resource Name (Arg3: \_SB.GPIO in ASCII)
            }

            FixedDMA (SDMA_REQ_UART2_RX, 4, Width8Bit, )
            FixedDMA (SDMA_REQ_UART2_TX, 3, Width8Bit, )

            UARTSerialBus (
            115200,
            DataBitsEight,
            StopBitsOne,
            0,                // LinesInUse
            LittleEndian,
            ParityTypeNone,
            FlowControlNone,
            0,
            0,
            "\\_SB.CPU0",
            0,
            ResourceConsumer,
            ,)
        })
        Return(RBUF)
    }

  Name (_DSD, Package () {
    ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package (2) {"SerCx-FriendlyName", "UART2"}
      }
  })
}

Device (UAR3)
{
    Name (_HID, "NXP0113") //NXP0113 for 24MHz UART_CLK_ROOT
    Name (_UID, 0x3)
    Name (_DDN, "UART3")
    Method (_STA)
    {
       Return(0xF)
    }
    Method (_CRS, 0x0, NotSerialized) {
        Name (RBUF, ResourceTemplate () {
            MEMORY32FIXED(ReadWrite, 0x30880000, 0x4000, )
            Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 60 }

            // UART3_RTS_B - ECSPI1_SS0  - GPIO5_IO09 - 137
            // UART3_CTS_B - ECSPI1_MISO - GPIO5_IO08 - 136
            // MsftFunctionConfig (Exclusive, PullUp, IMX_ALT1, "\\_SB.GPIO", 0,
            // ResourceConsumer, ) { 136, 137 }
            //
            // MsftFunctionConfig (Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6) { Pin List }
            VendorLong () {
              MSFT_UUID,            // Vendor UUID (MSFT UUID)
              MSFT_FUNCTION_CONFIG, // Resource Identifier (MSFT Function Config)
              0x1d,0x00,            // Length (0xF + sizeof(PinList) + sizeof(ResourceName))
              0x01,                 // Revision (0x1)
              RESOURCECONSUMER_EXCLUSIVE, // Flags (Arg5 | Arg0: ResourceConsumer | Exclusive)
              PULL_UP,              // Pin configuration (Arg1: PullUp)
              IMX_ALT1,0x00,        // Function Number (Arg2: IMX_ALT1)
              PIN_TABLE_OFFSET,     // Pin Table Offset (0x12)
              0x00,                 // Resource Source Index (Arg4: 0)
              0x16,0x00,            // Resource Source Name Offset (0x12 + sizeof(PinList))
              0x20,0x00,            // Vendor Data Offset (0x12 + sizeof(PinList) + sizeof(ResourceName))
              0x00,0x00,            // Vendor Data Length (sizeof(Arg6) = 0)
              0x88,0x00,0x89,0x00,  // Pin List (136, 137)
              SB_GPIO               // Resource Name (Arg3: \_SB.GPIO in ASCII)
            }

            // UART3_RX_DATA - GPIO5_IO26 - 154
            // UART3_TX_DATA - GPIO5_IO27 - 155
            // MsftFunctionConfig (Exclusive, PullUp, IMX_ALT0, "\\_SB.GPIO", 0,
            // ResourceConsumer, ) { 154, 155 }
            //
            // MsftFunctionConfig (Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6) { Pin List }
            VendorLong () {
              MSFT_UUID,            // Vendor UUID (MSFT UUID)
              MSFT_FUNCTION_CONFIG, // Resource Identifier (MSFT Function Config)
              0x1d,0x00,            // Length (0xF + sizeof(PinList) + sizeof(ResourceName))
              0x01,                 // Revision (0x1)
              RESOURCECONSUMER_EXCLUSIVE, // Flags (Arg5 | Arg0: ResourceConsumer | Exclusive)
              PULL_UP,              // Pin configuration (Arg1: PullUp)
              IMX_ALT0,0x00,        // Function Number (Arg2: IMX_ALT0)
              PIN_TABLE_OFFSET,     // Pin Table Offset (0x12)
              0x00,                 // Resource Source Index (Arg4: 0)
              0x16,0x00,            // Resource Source Name Offset (0x12 + sizeof(PinList))
              0x20,0x00,            // Vendor Data Offset (0x12 + sizeof(PinList) + sizeof(ResourceName))
              0x00,0x00,            // Vendor Data Length (sizeof(Arg6) = 0)
              0x9a,0x00,0x9b,0x00,  // Pin List (154, 155)
              SB_GPIO               // Resource Name (Arg3: \_SB.GPIO in ASCII)
            }

            FixedDMA (SDMA_REQ_UART3_RX, 6, Width8Bit, )
            FixedDMA (SDMA_REQ_UART3_TX, 5, Width8Bit, )

            UARTSerialBus (
            115200,
            DataBitsEight,
            StopBitsOne,
            0xC0,                // LinesInUse
            LittleEndian,
            ParityTypeNone,
            FlowControlNone,
            0,
            0,
            "\\_SB.CPU0",
            0,
            ResourceConsumer,
            ,)
        })
        Return(RBUF)
    }

  Name (_DSD, Package () {
    ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package (2) {"SerCx-FriendlyName", "UART3"}
      }
  })
}

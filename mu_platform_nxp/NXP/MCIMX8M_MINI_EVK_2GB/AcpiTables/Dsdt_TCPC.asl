/*
* This file is derived from Microsoft example available on https://github.com/microsoft/Windows-driver-samples/blob/master/usb/UcmTcpciCxClientSample
* Original file licensing:
* Copyright (c) 2015 Microsoft
* SPDX-License-Identifier: MS-PL
* NXP modifications are licensed under the same license
* Copyright 2020 NXP
*
*/
#include "UcmTcpciConstatnts.h"

// UCM-TCPCI device. Can be named anything.
Device(USBC)
{
    // This device needs to be enumerated by ACPI, so it needs a HWID.
    // Your INF should match on it.
    Name(_HID, "USBC0001")
    Method(_CRS, 0x0, NotSerialized)
    {
        Name (RBUF, ResourceTemplate ()
        {
            //
            // Sample I2C and GPIO resources.
            // platform's underlying controllers and connections.
            // \_SB.I2C and \_SB.GPIO are paths to predefined I2C and GPIO controller instances.
            //  GPIO2_IO011 SD1_STROBE
            I2CSerialBus(0x50, ControllerInitiated, 400000, AddressingMode7Bit, "\\_SB.I2C2")
            GpioIO(Shared, PullNone, 0, 0, IoRestrictionNone, "\\_SB.GPIO", 0, ResourceConsumer, , ) { 43 } // 1 * 32 + 11
            GpioInt(Level, ActiveLow, Exclusive, PullUp, 0, "\\_SB.GPIO",) { 43 }
        })
        Return(RBUF)
    }
    // Inside the scope of the UCM-TCPCI device, you need to define one "connector" device.
    // It can be named anything.
    Device(CON0)
    {
        // This device is not meant to be enumerated by ACPI, hence you should not assign a
        // HWID to it. Instead, use _ADR to assign address 0 to it.
        Name(_ADR, 0x00000000)

        // _PLD as defined in the ACPI spec. The GroupToken and GroupPosition are used to
        // derive a unique "Connector ID". This PLD should correlate with the PLD associated
        // with the XHCI device for the same port.
        Name(_PLD, Package()
        {
            Buffer()
            {
                0x82,                   // Revision 2, ignore color.
                0x00,0x00,0x00,         // Color (ignored).
                0x00,0x00,0x00,0x00,    // Width and height.
                0x69,                   // User visible; Back panel; VerticalPos:Center.
                0x0c,                   // HorizontalPos:0; Shape:Vertical Rectangle; GroupOrientation:0.
                0x80,0x00,              // Group Token:0; Group Position:1; So Connector ID is 1.
                0x00,0x00,0x00,0x00,    // Not ejectable.
                0xFF,0xFF,0xFF,0xFF     // Vert. and horiz. offsets not supplied.
            }
        })

        // _UPC as defined in the ACPI spec.
        Name(_UPC, Package()
        {
            0x01,                       // Port is connectable.
            0x08,                       // Type C connector - USB2-only.
            0x00000000,                 // Reserved0 must be zero.
            0x00000000                  // Reserved1 must be zero.
        })

        Name(_DSD, Package()
        {
            // The UUID for Type-C connector capabilities.
            ToUUID("6b856e62-40f4-4688-bd46-5e888a2260de"),

            // The data structure which contains the connector capabilities. Each package
            // element contains two elements: the capability type ID, and the capability data
            // (which depends on the capability type). Note that any information defined here
            // will override similar information described by the driver itself. For example, if
            // the driver claims the port controller is DRP-capable, but ACPI says it is UFP-only
            // ACPI will take precedence.

            Package()
            {
                Package() {1, 4},                                    // Supported operating modes (DRP).
                Package() {2, USB_TYPE_C_SOURCE_DEFAULT},            // Supported Type-C sourcing capabilities. (USB 2.0 - 500 mA, USB 3.1 - 900 mA)
                Package() {3, 0},                                    // Audio accessory capable (False).
// Uncoment next line for Power delivery setting example
//#define PD_TEST
#ifndef PD_TEST
                Package() {4, 0},                                    // Is PD supported (False).
#else
                Package() {4, 1},                                    // Is PD supported (True)
                Package() {5, 3},                                    // Supported power roles (Sink and Source).
                Package() {6, Package() {                            // Capability type ID of PD Source Capabilities.
                                  PD_SRC_FX(1,0,0,1,0,0,0,5000,1000) // Source PDO #0: Fixed: DRP=1, USB_SUSP=0, UC=0, USB_CC=1, DRD=0, UEM=0, PK=0, U=5V, I=1A.
                              }},
                Package() {7, Package () {                           // Capability type ID of PD Sink Capabilities.
                                  PD_SNK_FX(1,1,0,1,0, 5000,1000),   // Sink PDO #0: Fixed: DRP=1, HC=0, UC=0, USB_CC=1, DRD=0, U= 5V,  I=1A.
                                  PD_SNK_FX(1,1,0,1,0,15000,2500),   // Sink PDO #0: Fixed: DRP=1, HC=0, UC=0, USB_CC=1, DRD=0, U=15V,  I=2.5A.
                              }},
#endif
            }
        })
    } // Device(CON0)
} // Device(USBC)
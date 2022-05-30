IMXUART Readme

IMXUART is serial controller driver using SerCx2 framework.

IMXUART supports the optional creation a device interface to allow usermode clients to
open and use the serial port like a conventional serial port. To enable this functionality,
you must declare a UARTSerialBus() descriptor in it's ACPI resource declaration,
and supply a value for the ACPI _DDN (Dos Device Name) field.

Both the UARTSerialBus() macro and the _DDN are optional. If UARTSerialBus() is not specified,
a device interface will not be created. If _DDN is not specified, the port will not be
assigned a friendly name.

The LinesInUse field is used to determine whether RTS/CTS flow control should
be allowed. If the RTS/CTS pins on this UART instance are not exposed,
set LinesInUse to 0. If the RTS/CTS pins are exposed, set LinesInUse to 0xC0.

XON/XOFF software flow control is supported in driver in interrupt mode
and it can be enabled at receiver side, transmitter side or both. At transmitter side
the driver stops transmission if XOFF received and resumes when XON is received.
At receiver side the driver sends XOFF if overwhelmed by incoming bytes
(Number of received bytes exceed "XOFF Limit") and resumes when receiver is able to receive
more data by sending XON (Number of received bytes is under "XON Limit"). After XOFF character
is sent driver stops transmission of any data. "XOFF continue" mode is not supported.
"XOFF Pause transmission" character is 0x13. "XON Resume transmission character" is 0x11.
XON/XOFF character values cannot be configured from user application.


Example:

Device (UAR3)
{
   Name (_HID, "NXP0107")
   Name (_UID, 0x3)
   Name (_DDN, "UART3")
   Method (_STA)
   {
       Return(0xf)
   }
   Method (_CRS, 0x0, NotSerialized) {
       Name (RBUF, ResourceTemplate () {
           MEMORY32FIXED(ReadWrite, 0x021EC000, 0x4000, )
           Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) { 60 }

           // UART3_TX - EIM_D24 - GPIO3_IO24 - 88
           // UART3_RX - EIM_D25 - GPIO3_IO25 - 89
           MsftFunctionConfig(Exclusive, PullUp, IMX_ALT2, "\\_SB.GPIO", 0, ResourceConsumer, ) { 88, 89 }

           UARTSerialBus(
                9600,                  // InitialBaudRate: in BPS
                ,                      // BitsPerByte: default to 8 bits
                ,                      // StopBits: Defaults to one bit
                0xC0,                  // RTS, CTS
                                       // LinesInUse: 8 1bit flags to
                                       //   declare enabled control lines.
                ,                      // IsBigEndian:
                                       //   default to LittleEndian.
                ,                      // Parity: Defaults to no parity
                ,                      // FlowControl: Defaults to
                                       //   no flow control.
                1024,                  // ReceiveBufferSize
                1024,                  // TransmitBufferSize
                "\\_SB.CPU0",          // ResourceSource: dummy node name
                ,                      // ResourceSourceIndex: assumed to be 0
                ,                      // ResourceUsage: assumed to be
                                       //   ResourceConsumer
                ,                      // DescriptorName: creates name
                                       //   for offset of resource descriptor
                )                      // Vendor data
       })
       Return(RBUF)
   }
}

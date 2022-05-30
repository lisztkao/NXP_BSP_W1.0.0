Serial Logging Setup {#terminal-setup}
----
To help troubleshoot issues during boot, you can use the USB micro-B port on the i.MX EVK boards to output U-Boot and UEFI firmware serial debug logs to a host PC. The USB micro-B port on the EVK presents a virtual serial port to the host PC, which can be read by common Windows serial terminal applications such as HyperTerminal, Tera Term, or PuTTY.

1. Connect the target and the PC using a cable mentioned above.
2. Open Device Manager on the PC and locate the Enhanced Virtual serial device and note the COM port number.
3. Open terminal on the PC. Configure the Enhanced Virtual serial/COM port to 921600 baud/s, 8 bit, one stop bit.

In order for the Host PC to recognize the i.MX device's virtual serial port, you might need to download and install drivers for the i.MX's USB to serial converter.

The i.MX 8M EVK uses the CP210x USB to serial bridge. The CP210x driver can be found here: [https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers). 

The i.MX 8M Mini EVK uses the FT2232D USB to serial bridge. The FT2232D driver can be found under [http://www.ftdichip.com/Drivers/VCP.htm](http://www.ftdichip.com/Drivers/VCP.htm).

Note that the order that the serial/COM ports appear in Windows can differ between boards and between Windows hosts.

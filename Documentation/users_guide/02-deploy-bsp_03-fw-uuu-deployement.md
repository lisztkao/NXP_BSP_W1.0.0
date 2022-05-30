Deploy boot firmware {#deploy-firmware-uuu}
----

Prebuilt boot firmware (`firmware.bin`) is included in both binary and source BSP packages.
The boot firmware must be deployed to the eMMC on the board before deploying the Windows IoT image, otherwise the bootloader might not check the SD card for the Windows IoT image installer. 

### Firmware on eMMC
To flash the boot firmware to the eMMC we recommend to download UUU tool (Universal Update Utility) 1.3.191 which was used for BSP testing from https://github.com/NXPmicro/mfgtools/releases/tag/uuu_1.3.191.

*Note: The UUU tool requires U-boot with UUU download support enabled. For security reasons, its recommended to disable UUU download support in the U-Boot in final designs*

To deploy boot firmware to eMMC via USB download mode follow steps below:
1. Navigate to `firmware` directory. In the source package it is located in `imx-windows-iot/BSP/firmware`.
2. Download UUU tool and put it into `firmware\tools\uuu\uuu.exe`.
3. Begin preparing board by powering it off.
4. Switch the target board to USB download mode using DIP switches.
5. Connect a USB-C cable between your desktop and the board’s USB-C port.
6. Run `flash_bootloader.cmd /device NXPEVK_iMX8M_4GB` inside `firmware` directory.
7. When the process finishes power the board off. Disconnect the USB-C cable connecting board to PC. Not disconnecting from PC may cause errors in later steps.
8. Switch the board to eMMC boot mode. See [Basic Board Setup][]

UUU documentation can be found at [https://github.com/NXPmicro/mfgtools](https://github.com/NXPmicro/mfgtools).

### Firmware on SD card
During active development of the boot firmware, it can be time consuming and error-prone to repeatedly change the dip switches between UUU download mode and eMMC boot mode. To simplify this, the i.MX EVK boards support a SD Card boot mode that allows you to keep the boot firmware on the SD card. However, because the Windows IoT installer uses the SD card, if you need to install a new Windows IoT image, you must go back to flashing the boot firmware to eMMC using UUU download mode and setting the boot mode to boot from eMMC.

To deploy boot firmware to SD card from Windows we recommend to use Cfimager tool from https://www.nxp.com/webapp/Download?colCode=CF_IMAGER.

1. Navigate to `firmware` directory. In the source package it is located in `imx-windows-iot/BSP/firmware`.
2. Download NXP cfimager tool and put it into `firmware/cfimager.exe` or system `%PATH%`.
3. Plug SD card into the computer and run `flash_bootloader.cmd /device NXPEVK_iMX8M_4GB /target_drive <SD card letter eg. f:>` inside `firmware` directory.
   The `/device` could be `NXPEVK_iMX8M_4GB` or `NXPEVK_iMX8M_Mini_2GB`.
4. Begin preparing board by powering it off.
5. Switch the target board to boot form SD card using DIP switches. See [Basic Board Setup][]

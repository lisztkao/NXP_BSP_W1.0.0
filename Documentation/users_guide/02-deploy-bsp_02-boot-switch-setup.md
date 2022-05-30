Basic Board Setup {#boot-switch}
----

NXP i.MX EVK has three different boot modes that determine how the board boots. When the boot mode is set to SD card boot, the board assumes the firmware bootloader is on the SD card. When it's set to eMMC boot, the board assumes the firmware bootloader is on the eMMC. Finally, when the boot mode is set to USB UUU Download, the device goes into serial download mode and can have the eMMC flashed by a Host PC using the uuu.exe serial downloader.

Table: MCIMX8M-EVK boot DIP cfg

| SD card boot | eMMC boot | USB UUU Download |
|:-------------|:----------|:-----------------|
| ![DIP switch configuration](images/boards/imx8mq_bs_sd.png "DIP switch configuration"){width=3cm} | ![DIP switch configuration](images/boards/imx8mq_bs_emmc.png "DIP switch configuration"){width=3cm} | ![DIP switch configuration](images/boards/imx8mq_bs_usb_download.png "DIP switch configuration"){width=3cm} |


Table: MCIMX8MM-EVK boot DIP cfg

| SD card boot | eMMC boot | USB UUU Download |
|:-------------|:----------|:-----------------|
| ![DIP switch configuration](images/boards/imx8mm_bs_sd.png "DIP switch configuration"){width=3cm} | ![DIP switch configuration](images/boards/imx8mm_bs_emmc.png "DIP switch configuration"){width=3cm} | ![DIP switch configuration](images/boards/imx8mm_bs_usb_download.png "DIP switch configuration"){width=3cm} |

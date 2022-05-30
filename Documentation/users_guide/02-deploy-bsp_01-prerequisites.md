Deploy Windows IoT image to development board {#deploy-bsp}
====
This chapter will guide you through the deployment process of Windows operating system and boot firmware to the NXP development boards. At a high level, you will go through the following steps:
1. Obtain the BSP drivers + firmware, either by using the prebuilt package, or by building them from source
2. Use the serial downloader to flash the firmware to the board
3. Create a Windows IoT image that merges the BSP drivers with the Windows IoT Operating System
4. Prepare a micro SD card that contains a WinPE installer and the Windows IoT image
5. Boot the board with the prepared micro SD card inserted and wait for Windows IoT to install

Assuming you already have the BSP drivers + firmware ready, this process should take 1-2 hours.

## Hardware prerequisites
  * NXP i.MX development board (additional information can be found in Supported boards table in i.MX_Win10_Release_Notes.pdf)
  * USB-C cable to connect from device to PC
  * microSD card (minimum 8GB)
 
## Software prerequisites
  * Binary drivers and firmware (either downloaded from NXP.com or built locally)
  * Windows IoT operating system. There are two options:
    * **Recommended**: Windows 10 IoT Enterprise LTSC 2021 for Arm64 
      * *Preview available on Microsoft Collaborate
    [https://partner.microsoft.com/en-us/dashboard/collaborate/packages/12392]( https://partner.microsoft.com/en-us/dashboard/collaborate/packages/12392). Please contact Microsoft at WinIoT-on-NXP@microsoft.com for access* 
    * Windows 10 IoT Enterprise 21H2 GAC for Arm64
      * *Please contact a [Windows IoT distributor](https://github.com/MicrosoftDocs/windows-iot-public/tree/main/windows-iot-distributor-information) for access*
  * Windows ADK 1809 [https://docs.microsoft.com/en-us/windows-hardware/get-started/adk-install](https://docs.microsoft.com/en-us/windows-hardware/get-started/adk-install)
    * *Windows ADK 1809 is required for building firmware. If you are only creating a Windows IoT image, you can install Windows ADK for Windows 10, version 2004.*
  * Windows PE add-on for the ADK, version 2004. [https://docs.microsoft.com/en-us/windows-hardware/get-started/adk-install](https://docs.microsoft.com/en-us/windows-hardware/get-started/adk-install)
    * *Regardless of whether you installed ADK version 1809 or 2004, you should install version 2004 of WinPE.*
 

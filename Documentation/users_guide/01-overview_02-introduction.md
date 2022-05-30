How to start {#introduction}
----
The i.MX Windows 10 IoT BSP is a collection of binary files, source code, and support files you can
use to create a bootable Windows 10 IoT image for i.MX development systems.

Before you start, see the [Feature List per Board chapter](#feature-list).
This section lists all the i.MX boards covered by this BSP and also contains a list of possible features.

## Starting From Prebuilt Binaries
The Prebuild Binary package contains prebuilt release-signed binaries of the drivers and
firmware required for Windows 10 IoT Enterprise to run on the NXP i.MX EVK boards. It is the
fastest way to get started running on physical hardware. 

If you have downloaded the BSP with 
the Prebuilt Binaries, go to [Deploy Windows IoT image to development board](#deploy-bsp),  
which will guide you through creating a Windows IoT image that includes the BSP binaries and 
deploying it to an i.MX EVK board

## Starting From Source Files
The BSP Source Files package contains the source files of the drivers and firmware required
for Windows 10 IoT Enterprise to run on NXP i.MX EVK boards. It is intended to be used as
a reference for partners that have created their own hardware designs that use the i.MX 8
family of SoCs and need to customize the drivers and firmware for their own design.

If you have downloaded an archive with BSP sources, you will need to first build the Windows
drivers and Boot firmware from source before you can create a Windows IoT image and deploy it
to your device. Please start from [Building Windows 10 IoT for NXP i.MX Processors](#build-bsp), 
which will guide you through the process of the building the Windows drivers and boot
firmware from source. Once you have successfully built the driver and firmware binaries, you
can go back to the chapter that describes how to [Deploy Windows IoT image to development board](#deploy-bsp).

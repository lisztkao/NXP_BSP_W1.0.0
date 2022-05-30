Building the drivers in the BSP
----
Before you start building the BSP, you need to have an archive with latest BSP sources from NXP sites downloaded and extracted as described in [Obtaining BSP sources](#build-get-src) chapter.

### Required Tools
The following tools are required to build the drivers:
  * Visual Studio 2017
  * Windows Kits (ADK/SDK/WDK)

#### Visual Studio 2017
  * Make sure that you **install Visual Studio 2017 before the WDK** so that the WDK can install a required plugin.
  * Download [Visual Studio 2017](https://docs.microsoft.com/en-us/windows-hardware/drivers/other-wdk-downloads#step-1-install-visual-studio).
  * During install select **Desktop development with C++**.
  * During install select the following in the Individual components tab. If these options are not available try updating VS2017 to the latest release:
      * **VC++ 2017 version 15.9 v14.16 Libs for Spectre (ARM)**
      * **VC++ 2017 version 15.9 v14.16 Libs for Spectre (ARM64)**
      * **VC++ 2017 version 15.9 v14.16 Libs for Spectre (X86 and x64)**
      * **Visual C++ compilers and libraries for ARM**
      * **Visual C++ compilers and libraries for ARM64**

#### Windows Kits from Windows 10, version 1809
  * **IMPORTANT: Make sure that any previous versions of the ADK and WDK have been uninstalled!**
  * Install [ADK 1809](https://developer.microsoft.com/en-us/windows/hardware/windows-assessment-deployment-kit)
  * Install [WDK 1809](https://docs.microsoft.com/en-us/windows-hardware/drivers/other-wdk-downloads)
      * Scroll down and select Windows 10, version 1809.	
      * Make sure that you allow the Visual Studio Extension to install after the WDK install completes.
  * If the WDK installer says it could not find the correct SDK version, install [SDK 1809](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/)
      * Scroll down and select Windows 10 SDK, version 1809 (10.0.17763.0).
  * After installing all Windows Kits, restart computer and check if you have correct versions installed in Control panel.

### Structure of Windows driver sources

The *imx-windows-iot* - sources of Windows drivers has the following structure:

BSP - Contains boot firmware, driver binaries (Generated at build time.) and scripts needed to deploy BSP to development board.

build - Contains build scripts, and the VS2017 solution file.

components - Contains third party binaries and utility projects.

driver - Contains driver sources.

hals - Contains hal extension sources.

### One-Time Environment Setup
Test certificates must be installed to generate driver packages on a development machine.
 1. Open an Administrator Command Prompt.
 2. Navigate to your BSP and into the folder `imx-windows-iot\build\tools`.
 3. Launch `StartBuildEnv.bat`.
 4. Run `SetupCertificate.bat` to install the test certificates.

Some tools may not work correctly if LongPath is not enabled, therefore run following command in console:
 1. Execute `reg add HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\FileSystem /v LongPathsEnabled  /t REG_DWORD  /d 1` command.

### Building the drivers

 1. Open the solution imx-windows-iot\build\solution\iMXPlatform\iMXPlatform.sln located in the path where you have extracted BSP archive.
 
    > Note Microsoft pkggen requires launching Visual Studio 2017 as Administrator. Although driver projects are configured not to generate packages BSP might contain miscellaneous projects that require launching Visual Studio as Administrator to build successfully.
 2. Choose `Debug` or `Release` build type.
 3. If secure boot feature is enabled it is required to use signed drivers.
 4. To build press Ctrl-Shift-B or choose Build -> Build Solution from menu. This will compile all driver packages then `imx-windows-iot\BSP\IoTEntOnNXP\drivers` for deployment.
 5. The updated drivers could now be injected into the installation image or manually  installed to running development board.
      - To manually install drivers it has to be copied to development board via USB drive, network share, scp, remote desktop.
        Driver can be installed either by clicking `install` in right click menu of 'inf' file or by devcon command-line utility.
      - For debug use the `.kdfiles` of WinDBG. Then to initiate driver reload either use devcon or reset the board.
      - To create new installation SD card follow [Deploy Windows IoT image to development board][]

Install Windows IOT Enterprise to eMMC {#deploy-os-winpe}
----

Currently, the only way to deploy a Windows IoT Enterprise to the onboard eMMC is to use the WinPE OS (Windows Preinstallation Environment) to write the Windows IoT image to eMMC. WinPE is a small Windows manufacturing OS that can be fully loaded and run from memory without using persistent storage. We will create an SD card with WinPE and a Windows IoT image that contains the BSP drivers. The boot firmware will check the SD card and boot WinPE, which will then install the Windows IoT image to the eMMC.

We will list commands for an MCIMX8M-EVK board. The tools and techniques can be adapted to other hardware designs.

### Preparing WinPE based installation media on a microSD card

#### Prepare Windows IoT image with prebuilt drivers
 1. Download W21H2-X.X.X-imx-windows-bsp-binaries.zip and extract it. If you are building the drivers yourself, follow the steps in the section titled [Prepare Windows IoT image with drivers from sources yourself][].
 2. Open elevated command prompt and navigate to extracted `<imx-windows-bsp-binaries>\IoTEntOnNXP`.
 3. Continue to [Common steps][]

#### Prepare Windows IoT image with drivers from sources yourself
 1. Build the drivers yourself as described in [Building Windows 10 IoT for NXP i.MX Processors][]. If you are using the pre-built binaries, follow the steps in the section titled [Prepare Windows IoT image with prebuilt drivers][].
 2. After the BSP has been built open elevated command prompt and navigate to `<BSP_DIR>\imx-windows-iot\BSP\IoTEntOnNXP`.
 3. Continue to [Common steps][]

#### Common steps
 1. Download the Windows IoT Enterprise version ISO mentioned in [Software prerequisites][].
 2. After the ISO file have been downloaded, mount the ISO file and copy out the install.wim from `<DVD mount drive:>\sources\install.wim` to the `IoTEntOnNXP` directory.
 3. In the `IoTEntOnNXP` directory run `make-winpe-enterprise.cmd` in elevated prompt.
    This will create copy of selected install.wim image with injected i.MX drivers.
    
    *Note: Be sure to copy whole command line. Commands with many parameters may be split into multiple lines in the following examples.*
    
    For release signed drivers (e.g. NXP precompiled drivers) you can use:
    
    ```bash
    make-winpe-enterprise.cmd /device NXPEVK_iMX8M_4GB /disable_updates /disable_transparency /image ..\install.wim
    ```
    
    During development, you will want to add a few additional development flags to allow test-signed drivers and to enable windbg debugging, as in the below:
        
    ```bash
    make-winpe-enterprise.cmd /device NXPEVK_iMX8M_4GB /disable_updates /disable_transparency /patch_sdport /test_signing /winpedebug /windebug /image ..\install.wim
    ```
    
    Notes to parameters:
      - The `/image <WIM_PATH>` could be either absolute or relative to `IoTEntOnNXP\work`. Directory `work` might not exist yet. The script will create it and then enter it.
      - Use `/disable_updates` to prevent Windows from automatically searching for and installing updates, which can slow down a device and reduce available storage.
      - Use `/disable_transparency` to improve UI responsiveness. This is improved in the KB5011543 Windows update.
      - Use `/patch_sdport` to update Sdport.sys. This option should to enabled during development if you are creating an installer for the `19044.1288.211006` Windows OS build, which has a bug in sdport.sys that can cause the blue bug check screen. The patched sdport.sys in this BSP is test signed and will cause blue screen if testsigning is disabled. It should NOT be used in production designs. See limitations in release notes for more information.
      - Use `/winpedebug` to enable Windows PE debug through the serial port.
      - Use `/windebug` to enable Windows IoT debug through the serial port.
      - Use `/test_signing` to enable test signing.
      - Use `/device` could be `NXPEVK_iMX8M_4GB` or `NXPEVK_iMX8M_Mini_2GB`.
    
 4. Now you can deploy the WinPE image to an SD card by `make-winpe-enterprise.cmd /apply <disk_number>`.
 
     ```bash
    make-winpe-enterprise.cmd /device NXPEVK_iMX8M_4GB /apply <disk_number>
    ```
    
    The `disk_number` of your SD card can be obtained:
      - As 'Disk ###' using Diskpart.
        ```
        diskpart
        Microsoft DiskPart version 10.0.19041.964
        
        Copyright (C) Microsoft Corporation.
        On computer: NXL70483
        
        DISKPART> list disk
        
          Disk ###  Status         Size     Free     Dyn  Gpt
          --------  -------------  -------  -------  ---  ---
          Disk 0    Online          953 GB   195 GB        *
          Disk 1    Online         7580 MB      0 B        *
        
        DISKPART> exit
        
        Leaving DiskPart...
        ```
        
      - From the DeviceID string using wmic.
        
        ```
        wmic diskdrive list brief
        Caption                  DeviceID            Model                    Partitions  Size
        SDHC Card                \\.\PHYSICALDRIVE1  SDHC Card                2           7945620480
        
        # The format is \\.\PHYSICALDRIVE<disk_number>.
        ```
    
 5. WinPE based Windows installer is now deployed on the SD card.


 6. After you deploy boot firmware (see [Deploy boot firmware][]) you can insert the prepared SD card installer into your development board and power it on.
    Board will boot into the installer. Installer will flash Windows IoT Enterprise to the eMMC, then reboot into installed Windows. Installing Windows IoT Enterprise from the SD card can take around 30 minutes, so get some coffee while you wait!

    *Note: The WinPE installer renames the `EFI` folder at the root of SD card to `_efi`, which causes UEFI to skip the SD card at boot time. This allows you to keep the SD card inserted across reboots without having Windows IoT reinstalled each reboot. If you wish to boot into the WinPE installer again, you can rename `_efi` back to `EFI`.*
    
 7. Make sure to disable sleep in "Power & sleep" settings after the Windows os boots up to avoid unexpected system hangs.

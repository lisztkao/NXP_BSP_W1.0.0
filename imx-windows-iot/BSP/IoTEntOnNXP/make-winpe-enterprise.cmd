@echo off
:: Copyright 2020 NXP 
:: All rights reserved. 
::  
:: Redistribution and use in source and binary forms, with or without modification, 
:: are permitted provided that the following conditions are met: 
::
:: Redistributions of source code must retain the above copyright notice, this list 
:: of conditions and the following disclaimer. 
::
:: Redistributions in binary form must reproduce the above copyright notice, this 
:: list of conditions and the following disclaimer in the documentation and/or 
:: other materials provided with the distribution. 
::
:: Neither the name of the copyright holder nor the names of its 
:: contributors may be used to endorse or promote products derived from this 
:: software without specific prior written permission. 
::
:: THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
:: ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
:: WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
:: DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR 
:: ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
:: (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
:: LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
:: ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
:: (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
:: SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
:: 

::
:: Run this script in order to prepare a WinPE image for boot on i.MX 8M and i.MX 8M Mini.
::

setlocal enableextensions disabledelayedexpansion

set WINPE_DIR=%ProgramFiles(x86)%\Windows Kits\10\Assessment and Deployment Kit\Windows Preinstallation Environment\arm64
set DEST=winpe_imx
set WIN_IMG=%DEST%\install.wim
set SWM_IMG=%DEST%\install.swm
set FFU_DISK_NUM=0
set WINPE_DRIVE_LETTER=O
set SCRIPT_DIR=%~dp0
set DISABLE_UPDATES=
set DISABLE_TRANSPARENCY=
set PATCH_SDPORT=
set UNATTEND=
set TEST_SIGNING=
set CUMULATIVE_UPDATE_PATH=

:: Parse options
:GETOPTS
 if /I "%~1" == "/?" ( goto USAGE
 ) else (if /I "%~1" == "/Help" ( goto USAGE
 ) else (if /I "%~1" == "/image" ( set IMAGE_PATH=%2& shift
 ) else (if /I "%~1" == "/cumulative_update" ( set CUMULATIVE_UPDATE_PATH=%2& shift
 set SPLIT_WIM=1
 ) else (if /I "%~1" == "/apply" ( set DISK_NUM=%2& shift
 ) else (if /I "%~1" == "/device" ( set DEV_NAME=%2& shift
 ) else (if /I "%~1" == "/clean" ( set CLEAN=1
 ) else (if /I "%~1" == "/winpedebug" ( set WINPE_DEBUG=1
 ) else (if /I "%~1" == "/windebug" ( set WIN_DEBUG=1
 ) else (if /I "%~1" == "/test_signing" ( set TEST_SIGNING=1
 ) else (if /I "%~1" == "/splitwim" ( set SPLIT_WIM=1
 ) else (if /I "%~1" == "/patch_sdport" ( set PATCH_SDPORT=1
 ) else (if /I "%~1" == "/disable_updates" ( set DISABLE_UPDATES=1
 ) else (if /I "%~1" == "/disable_transparency" ( set DISABLE_TRANSPARENCY=1
 ) else (if /I "%~1" == "/unattend" ( set UNATTEND=1
 ) else goto USAGE
 ))))))))))))))
 shift
if not (%1)==() goto GETOPTS

if "%DEV_NAME%"=="" (
  echo The device type is incorrect.
  echo Please verify if your device is a NXPEVK_iMX8M_4GB and pass it to
  echo script with the /device flag.
  goto:eof
)

if "%DEV_NAME%"=="NXPEVK_iMX8M_4GB" ( set BOARD_DISKNUM=1
) else (if "%DEV_NAME%"=="NXPEVK_iMX8M_Mini_2GB" ( set BOARD_DISKNUM=0
) else goto USAGE
)

set DRIVER_DIR="%SCRIPT_DIR%\drivers"
set BINPATCH_DIR="%SCRIPT_DIR%\binpatch"

mkdir work > NUL 2>&1
cd work

:: make WIM mount directory
rmdir /s /q mount_winpe > NUL 2>&1
mkdir mount_winpe
pushd mount_winpe
set MOUNT_WINPE_DIR=%CD%
popd

:: make IoT Enterprise mount directory
rmdir /s /q mount_enterprise > NUL 2>&1
mkdir mount_enterprise
pushd mount_enterprise
set MOUNT_ENTERPRISE=%CD%
popd

if not "%CLEAN%" == "" goto CLEAN
if not "%DISK_NUM%" == "" goto APPLY

if "%IMAGE_PATH%" == "" (
    echo Please specify the path to the Windows IoT Enterprise image via the /image flag
    exit /b 1
)

if not exist %IMAGE_PATH% (
    echo The path to the Windows IoT Enterprise image seems to be incorrect
    exit /b 1
)	

:: make temporary WinPE directory
rmdir /s /q "%DEST%" > NUL 2>&1
mkdir "%DEST%"  
mkdir "%DEST%\sources"

:: copy WinPE files
echo Creating WinPE image layout at %DEST%
echo Copying WinPE files from %WINPE_DIR%
if not exist "%WINPE_DIR%\Media" (
    echo You must install the Windows PE Add-on for the ADK
    echo https://docs.microsoft.com/en-us/windows-hardware/manufacture/desktop/download-winpe--windows-pe
    goto err
)
xcopy /herky "%WINPE_DIR%\Media" "%DEST%\" || goto err
REM copy "%WINPE_DIR%\en-us\winpe.wim" "%DEST%\sources\boot.wim" || goto err
copy "%WINPE_DIR%\en-us\winpe.wim" "%DEST%\sources\boot_%DEV_NAME%.wim" || goto err
move "%DEST%\bootmgr.efi" "%DEST%\EFI\Microsoft\Boot\" || goto err

:: BCD
set TARGET_BCD_STORE=%DEST%\EFI\Microsoft\boot\bcd

if not "%WINPE_DEBUG%" == "" (
    echo Enabling kernel debugging for WinPE
    bcdedit /store "%TARGET_BCD_STORE%" /dbgsettings SERIAL DEBUGPORT:1 BAUDRATE:921600 || goto err
    bcdedit /store "%TARGET_BCD_STORE%" /debug {default} on || goto err
)

if not "%TEST_SIGNING%" == "" (
    echo Enable boot test/flight signing
    bcdedit /store "%TARGET_BCD_STORE%" /set {bootmgr} flightsigning on || goto err
    bcdedit /store "%TARGET_BCD_STORE%" /set {bootmgr} testsigning on || goto err
    
    echo Enable kernel test/flight signing...
    bcdedit /store "%TARGET_BCD_STORE%" /set {default} testsigning on || goto err
    bcdedit /store "%TARGET_BCD_STORE%" /set {default} flightsigning on || goto err
)

mkdir "%MOUNT_WINPE_DIR%" > NUL 2>&1
echo Mounting WIM at %MOUNT_WINPE_DIR%
dism /mount-wim /wimfile:"%DEST%\sources\boot_%DEV_NAME%.wim" /mountdir:"%MOUNT_WINPE_DIR%" /index:1 || goto err

echo Creating the startnet.cmd script
set STARTNET_CMD=%MOUNT_WINPE_DIR%\Windows\System32\startnet.cmd
echo echo Setting up drive letter %WINPE_DRIVE_LETTER% for WinPE >> "%STARTNET_CMD%"
echo ( echo sel disk %BOARD_DISKNUM%  >> "%STARTNET_CMD%"
echo echo sel partition 2 >> "%STARTNET_CMD%"
echo echo assign letter=%WINPE_DRIVE_LETTER% ) ^| diskpart >> "%STARTNET_CMD%"

echo Appending FFU flashing commands to %STARTNET_CMD%
echo echo Partitioning the drive >> "%STARTNET_CMD%"
echo diskpart /s %WINPE_DRIVE_LETTER%:\diskpart.txt >> "%STARTNET_CMD%"

echo echo Deploying IoT Enterprise to eMMC >> "%STARTNET_CMD%"

if not "%SPLIT_WIM%" == "" (
    echo dism /Apply-Image /ImageFile:"%WINPE_DRIVE_LETTER%:\install.swm" /SWMFile:"%WINPE_DRIVE_LETTER%:\install*.swm" /Index:2 /ApplyDir:W:\ /Compact >> "%STARTNET_CMD%"
) else (
    echo dism /Apply-Image /ImageFile:"%WINPE_DRIVE_LETTER%:\install.wim" /Index:2 /ApplyDir:W:\ /Compact >> "%STARTNET_CMD%"
)

echo echo Setting up BCD >> "%STARTNET_CMD%"
echo W:\Windows\System32\bcdboot.exe W:\Windows /s S: >> "%STARTNET_CMD%"
if not "%TEST_SIGNING%" == "" (
    echo W:\Windows\System32\bcdedit.exe /store S:\EFI\microsoft\Boot\BCD /set {default} testsigning on >> "%STARTNET_CMD%"
)

if not "%WIN_DEBUG%" == "" (
    echo echo Enabling kernel debugging for Windows
    echo W:\Windows\System32\bcdedit.exe /store S:\EFI\microsoft\Boot\BCD /dbgsettings SERIAL DEBUGPORT:1 BAUDRATE:921600 >> "%STARTNET_CMD%"
    echo W:\Windows\System32\bcdedit.exe /store S:\EFI\microsoft\Boot\BCD /debug {default} on >> "%STARTNET_CMD%"
)

echo echo Disable Fast Startup >> "%STARTNET_CMD%"
echo REG LOAD HKLM\OFFLINE_SYSTEM W:\Windows\System32\config\SYSTEM >> "%STARTNET_CMD%"
echo REG ADD "HKLM\OFFLINE_SYSTEM\ControlSet001\Control\Session Manager\Power" /V HiberbootEnabled /T REG_DWORD /D 0 /F >> "%STARTNET_CMD%"
echo REG UNLOAD HKLM\OFFLINE_SYSTEM >> "%STARTNET_CMD%"

:: HKLM\OFFLINE_SOFTWARE registry update section

echo REG LOAD HKLM\OFFLINE_SOFTWARE W:\Windows\System32\config\SOFTWARE >> "%STARTNET_CMD%"

echo echo Hide Sleep button >> "%STARTNET_CMD%"
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FlyoutMenuSettings" /V ShowSleepOption /T REG_DWORD /D 0 /F >> "%STARTNET_CMD%"

echo REG ADD "HKLM\OFFLINE_SOFTWARE\Microsoft\Windows\CurrentVersion\DeviceAccess\Classes\{ADA9253B-628C-40CE-B2C1-19F489A0F3DA}" /V Policy /T REG_DWORD /D 1 /F >> "%STARTNET_CMD%"
:: H.264
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {34363248-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: H.
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {35363248-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: HEVC
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {43564548-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: VP80
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {30385056-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: VP90
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {30395056-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: MPEG-4 Simple Profile
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {5334504D-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: MPEG-4 ASP
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {3253344D-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: MPEG-4 Part 2
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {5634504D-0000-0010-8000-00AA00389B71} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"
:: MPEG-2
echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\Preferred" /V {E06D8026-DB46-11CF-B4D1-00805F6CBBEA} /T REG_SZ /D {8A12D5A9-69EC-4FE2-BF16-7B4C857D0DC0} /F >> "%STARTNET_CMD%"

echo REG ADD "HKLM\OFFLINE_SOFTWARE\Classes\MediaFoundation\Transforms\62ce7e72-4c71-4d20-b15d-452831a87d9d" /V MFTFLAGS /T REG_DWORD /D 00000008 /F >> "%STARTNET_CMD%"

echo echo Remove OneDrive >>  "%STARTNET_CMD%"
echo del /f /q W:\windows\SysWOW64\OneDriveSetup.exe >>  "%STARTNET_CMD%"

if not "%DISABLE_UPDATES%" == "" (
    echo echo Disable automatic updates >> "%STARTNET_CMD%"
    echo REG ADD "HKLM\OFFLINE_SOFTWARE\Policies\Microsoft\Windows\WindowsUpdate\AU " /V NoAutoUpdate /T REG_DWORD /D 1 /F >> "%STARTNET_CMD%"
)

echo REG UNLOAD HKLM\OFFLINE_SOFTWARE >> "%STARTNET_CMD%"

if not "%DISABLE_TRANSPARENCY%" == "" (
    echo echo Disable automatic updates >> "%STARTNET_CMD%"
    echo REG LOAD HKLM\TEMP W:\Users\Default\NTUSER.DAT >> "%STARTNET_CMD%"
    echo REG ADD "HKLM\TEMP\Software\Microsoft\windows\CurrentVersion\Themes\Personalize" /V EnableTransparency /T REG_DWORD /D 0 /F >> "%STARTNET_CMD%"
    echo REG UNLOAD HKLM\TEMP >> "%STARTNET_CMD%"
)

echo echo Renaming the WinPE EFI partition >> "%STARTNET_CMD%"
echo ren %WINPE_DRIVE_LETTER%:\efi _efi >> "%STARTNET_CMD%"

echo echo Successfully flashed new image to eMMC. Restarting the device... >> "%STARTNET_CMD%"
echo timeout /t 10 >> "%STARTNET_CMD%"
echo wpeutil reboot >> "%STARTNET_CMD%"

echo Injecting drivers from %DRIVER_DIR% into WinPE WIM
dism /Image:"%MOUNT_WINPE_DIR%" /Add-Driver /Driver:%DRIVER_DIR% /Recurse /ForceUnsigned || goto err

echo copying %IMAGE_PATH% to %DEST%
copy %IMAGE_PATH% %WIN_IMG%

echo Injecting drivers from %DRIVER_DIR% into Enterprise WIM
dism /mount-wim /wimfile:%WIN_IMG% /mountdir:%MOUNT_ENTERPRISE% /index:2 || goto err
dism /Image:"%MOUNT_ENTERPRISE%" /Add-Driver /Driver:%DRIVER_DIR% /Recurse /ForceUnsigned || goto err

if not "%CUMULATIVE_UPDATE_PATH%" == "" (
	echo Installing updates from %CUMULATIVE_UPDATE_PATH% into Enterprise WIM
	dism /Image:"%MOUNT_ENTERPRISE%" /Add-Package /PackagePath="%CUMULATIVE_UPDATE_PATH%" || goto err
)

echo Add disptrl.dll to system32
xcopy /Y /R /F %DRIVER_DIR%\Galcore\dispctrl.dll %MOUNT_ENTERPRISE%\windows\system32\drivers
dir %MOUNT_ENTERPRISE%\windows\system32\drivers\dispctrl.dll || goto err

if not "%PATCH_SDPORT%" == "" (
    echo Apply sdport test binary
	takeown /f %MOUNT_ENTERPRISE%\windows\system32\drivers\sdport.sys
	icacls %MOUNT_ENTERPRISE%\windows\system32\drivers\sdport.sys /grant administrators:f
	xcopy /Y /R /F %BINPATCH_DIR%\Sdport\sdport.sys %MOUNT_ENTERPRISE%\windows\system32\drivers || goto err
	dir %MOUNT_ENTERPRISE%\windows\system32\drivers\sdport.sys || goto err
)

if not "%UNATTEND%" == "" (
	md %MOUNT_ENTERPRISE%\Windows\Panther
	xcopy /Y /R /F "%SCRIPT_DIR%\unattend.xml" %MOUNT_ENTERPRISE%\Windows\Panther
	dir %MOUNT_ENTERPRISE%\Windows\Panther\unattend.xml || goto err
)

dism /unmount-wim /mountdir:%MOUNT_ENTERPRISE% /commit || goto err

echo copying the diskpart script to %DEST%
copy "%SCRIPT_DIR%\scripts\diskpart_%DEV_NAME%.txt" %DEST% || goto err

echo Unmounting WIM
dism /unmount-wim /mountdir:"%MOUNT_WINPE_DIR%" /commit || goto err

if not "%SPLIT_WIM%" == "" (
    echo splitting image file
    dism /split-image /ImageFile:%WIN_IMG% /SWMFile:%SWM_IMG% /FileSize:4000
    del %WIN_IMG%
)

echo Success
exit /b 0

:APPLY
    echo Applying image at %DEST% to physical disk %DISK_NUM%
    if not exist "%DEST%" (
    echo No WinPE media directory found at %DEST%. Run the first form of this script to generate WinPE image layout.
        exit /b 1
    )

    echo select disk %DISK_NUM% > diskpart.txt
    echo clean >> diskpart.txt
    echo convert gpt NOERR >> diskpart.txt

    :: EFI partition
    echo create partition primary id=c12a7328-f81f-11d2-ba4b-00a0c93ec93b size=32 >> diskpart.txt
    echo create partition primary >> diskpart.txt
    echo format fs=fat32 label="WinPE" quick >> diskpart.txt
    echo assign >> diskpart.txt
    echo assign mount="%MOUNT_WINPE_DIR%" >> diskpart.txt

    echo Formatting disk %DISK_NUM% and mounting to %MOUNT_WINPE_DIR%...
    diskpart /s diskpart.txt || exit /b 1

    echo Copying files from %DEST% to %MOUNT_WINPE_DIR%
    xcopy /herky "%DEST%\*.*" "%MOUNT_WINPE_DIR%\" || exit /b 1
    echo Copying files from %DEST% to %MOUNT_WINPE_DIR% 2
    move "%MOUNT_WINPE_DIR%\sources\boot_%DEV_NAME%.wim" "%MOUNT_WINPE_DIR%\sources\boot.wim"
    echo Copying files from %DEST% to %MOUNT_WINPE_DIR% 3
    move "%MOUNT_WINPE_DIR%\diskpart_%DEV_NAME%.txt" "%MOUNT_WINPE_DIR%\diskpart.txt"
    echo Copying files from %DEST% to %MOUNT_WINPE_DIR% 4

    mountvol "%MOUNT_WINPE_DIR%" /d
    timeout /t 10 /nobreak

    echo Success
    exit /b 0

:CLEAN
    echo Cleaning up from previous run
    dism /unmount-wim /mountdir:"%MOUNT_ENTERPRISE%" /discard
    dism /unmount-wim /mountdir:"%MOUNT_WINPE_DIR%" /discard
    rmdir /s /q "%MOUNT_WINPE_DIR%" 2> NUL
    rmdir /s /q "%DEST%" 2> NUL
    del diskpart.txt
    exit /b 0

:USAGE
    echo make-winpe.cmd /image enterprise_image_path
    echo   [/winpedebug]
    echo make-winpe.cmd /apply disk_number
    echo make-winpe.cmd /clean
    echo.
    echo Creates a WinPE image for i.MX
    echo Options:
    echo    /image                           Pass the path to the image containing IOT Enterprise
    echo    /device                          Which device shall the image be created for. {NXPEVK_iMX8M_4GB, NXPEVK_iMX8M_Mini_2GB}
    echo    /winpedebug                      Optionally enable debugging for WinPE.
    echo    /windebug                        Optionally enable debugging for Windows.
    echo    /test_signing                    Optionally enable driver test signing.
    echo    /splitwim                        Split wim file for install.wim ^> 4GB
    echo    /apply disk_number               Apply WinPE image to physical disk.
    echo    /disable_updates                 Disable automatic updates to save disk space.
    echo    /disable_transparency            Disable window transparency to improve UI responsivness.
    echo    /patch_sdport                    Update Sdport.sys in the Windows instalation. Use only for W10-19044.1288.211006 image.
    echo    /clean                           Clean up artifacts from a previous run.
    echo.
    echo Examples:
    echo.
    echo Create a WinPE image that deploys a Windows IOT Enterprise image to MMC.
    echo.
    echo    make-winpe.cmd /image D:\image\install.wim
    echo.
    echo Apply the WinPE image to an SD card (Physical Disk 7, use diskpart
    echo to find the disk number)
    echo.
    echo    make-winpe.cmd /apply 7
    echo.
    echo Clean up artifacts from a previous run of this script
    echo.
    echo    make-winpe.cmd /clean
    echo.
    exit /b 0

:err
    echo Script failed! Cleaning up
    dism /unmount-wim /mountdir:"%MOUNT_ENTERPRISE%" /discard
    dism /unmount-wim /mountdir:"%MOUNT_WINPE_DIR%" /discard
    rmdir /s /q "%MOUNT_WINPE_DIR%" 2> NUL
    rmdir /s /q "%DEST%" 2> NUL
    rmdir /s /q "%MOUNT_ENTERPRISE%" 2> NUL
    del diskpart.txt
    exit /b 1
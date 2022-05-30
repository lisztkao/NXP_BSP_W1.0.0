@ECHO OFF
:: Copyright 2022 NXP 
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
:: Run this script in order to deploy boot firmware.
::

:: Clear options
set DEVICE_TYPE=
set SIGNED_FW=
set TARGET_DRIVE=

:GETOPTS
 if /I "%~1" == "/?" goto USAGE
 if /I "%~1" == "/Help" goto USAGE
 if /I "%~1" == "/device" set DEVICE_TYPE=%2& shift
 if /I "%~1" == "/signed" set SIGNED_FW=signed_& shift
 if /I "%~1" == "/target_drive" set TARGET_DRIVE=%2& shift
 shift
if not (%1)==() goto GETOPTS

set FIRMWARE="%DEVICE_TYPE%\%SIGNED_FW%firmware.bin"

if not exist %FIRMWARE% (
  echo The device type is incorrect.
  echo Please verify if your device is a NXPEVK_iMX8M_4GB and pass it to
  echo script with the /device flag.
  goto:eof
)
:FLASH_SD_CARD
:: Write firmware to a drive plugged into PC using Cfimager. (https://www.nxp.com/webapp/Download?colCode=CF_IMAGER&appType=license&location=null)
:: Alternatively dd if="%FIRMWARE%" of="\\.\PhysicalDrive%DISK_NUM%" bs=512 seek=%SEEK% skip=0 .
if "%TARGET_DRIVE%"=="" (
  goto:FLASH_eMMC
)
   
if "%DEVICE_TYPE%" == "NXPEVK_iMX8M_4GB" (
  :: 66*512=0x8400
  set CF_IMAGER_OFFSET=0x8400
) else (
  if "%DEVICE_TYPE%" == "NXPEVK_iMX8M_Mini_2GB" (
    set CF_IMAGER_OFFSET=0x8400
  ) else (
    if "%DEVICE_TYPE%" == "EVK_iMX8MN_2GB" (
      :: 64*512=0x8000
      set CF_IMAGER_OFFSET=0x8000
    ) else (
      echo Error. The /device %DEVICE_TYPE% is not valid.
      goto:eof
    )
  )
)
cfimager.exe -raw -offset %CF_IMAGER_OFFSET% -f %FIRMWARE% -d %TARGET_DRIVE% || ^
echo Failed to write boot firmware to the "%TARGET_DRIVE%". Check the NXP cfimager.exe is available (eg. in path), TARGET_DRIVE is present and is not write protected.

goto:eof
:: End of SD_CARD_DOWNLOAD

:FLASH_eMMC
:: Write firmware to onboard memory.
SET device_mode=0

call:CHECK_DEVICE_MODE device_mode

IF "%device_mode%" == "none" (
	ECHO Device not in download mode
	ECHO Maybe device not connect with PC or device in normal mode.
	pause
	goto:eof
)

ECHO Device in %device_mode% download mode, start flash!!
ECHO.
tools\uuu\uuu.exe -b emmc %FIRMWARE%
pause
goto:eof

:CHECK_DEVICE_MODE
tools\uuu\uuu.exe -lsusb | findstr /r /c:"FB"
IF %ERRORLEVEL% == 0  (
  SET %~1=fastboot
  goto:eof
)

tools\uuu\uuu.exe -lsusb 2>&1 | findstr /r /c:"SDP"
IF %ERRORLEVEL% == 0  (
  SET %~1=serial
  goto:eof
)
SET %~1=none
goto:eof
:USAGE
echo flash_bootloader.cmd /device <NAME> [/signed] [/target_drive]
echo.
echo Flashes a firmware image
echo Options:
echo    /device                      {NXPEVK_iMX8M_4GB, NXPEVK_iMX8M_Mini_2GB, EVK_iMX8MN_2GB}
echo                                 Specifies the device
echo.
echo Optional options:
echo    /signed                      Specifies the signed firmware binary should be used.
echo    /target_drive                Specifies the firmware binary should be written to this drive
echo                                 instead of internal memory of the development board. Useful for
echo                                 firmware development.
echo                                 Caution, do not overwrite your system drive.
echo.
echo Examples:
echo.
echo Flash the Windows Enterprise firmware to the MMC of a EVK board.
echo    flash_bootloader.cmd /device NXPEVK_iMX8M_4GB /signed
echo.
echo Flash the Windows Enterprise firmware to an SD card.
echo    flash_bootloader.cmd /device NXPEVK_iMX8M_4GB /target_drive f:
echo.

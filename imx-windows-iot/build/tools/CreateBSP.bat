:: Copyright (c) Microsoft Corporation. All rights reserved.
:: Licensed under the MIT License.

@echo off
setlocal enableextensions disabledelayedexpansion

pushd %~dp0\..\..

if "%1"=="" (
    echo "Missing SOC argument to CreateBSP.bat"
    echo "Usage: CreateBSP.bat <SOC>"
    echo "eg: CreateBSP.bat iMX8"
    exit /b 1
)

if "%Configuration%"=="" (
    echo configuration environment variable is not set
    exit /b 1
)

if "%PLATFORM%"=="" (
    echo platform environment variable is not set
    exit /b 1
)

set SOC=%1
set REPO_ROOT=%cd%
set BSP_ROOT=%cd%\BSP\IoTEntOnNXP
set COMP_ROOT=%cd%\components
set DRVR_ROOT=%BSP_ROOT%\drivers
set BINPTCH_ROOT=%BSP_ROOT%\binpatch
set BUILD_ROOT=%REPO_ROOT%\build\solution\iMXPlatform\Build\%PLATFORM%\%Configuration%
set FAILURE=

echo BSP_ROOT is %BSP_ROOT%
echo BUILD_ROOT is %BUILD_ROOT%
echo DRVR_ROOT is %DRVR_ROOT%
echo BINPTCH_ROOT is %BINPTCH_ROOT%
echo REPO_ROOT is %REPO_ROOT%

if "%SOC%"=="iMX8" (
    goto ARM64
)

echo Unrecognized SOC type: %SOC%
exit /b 1

:ARM64

:: Copy Driver Packages
echo Copying Drivers to %DRVR_ROOT%
mkdir %DRVR_ROOT%\Audio >NUL 2>NUL
copy %BUILD_ROOT%\imxaud\* %DRVR_ROOT%\Audio\ >NUL
if errorlevel 1 (set FAILURE=imxaud & goto ERROR)
copy %REPO_ROOT%\driver\audio\controller\imxaud\imxaud.wm.xml %DRVR_ROOT%\Audio\ >NUL

mkdir %DRVR_ROOT%\GPIO >NUL 2>NUL
copy %BUILD_ROOT%\imxgpio\* %DRVR_ROOT%\GPIO\ >NUL
if errorlevel 1 (set FAILURE=imxgpio & goto ERROR)
copy %REPO_ROOT%\driver\gpio\imxgpio\imxgpio.wm.xml %DRVR_ROOT%\GPIO\ >NUL

mkdir %DRVR_ROOT%\I2C >NUL 2>NUL
copy %BUILD_ROOT%\imxi2c\* %DRVR_ROOT%\I2C\ >NUL
if errorlevel 1 (set FAILURE=imxi2c & goto ERROR)
copy %REPO_ROOT%\driver\i2c\imxi2c\imxi2c.wm.xml %DRVR_ROOT%\I2C\ >NUL

mkdir %DRVR_ROOT%\Net >NUL 2>NUL
copy %BUILD_ROOT%\imxnetmini\* %DRVR_ROOT%\Net\ >NUL
if errorlevel 1 (set FAILURE=imxnetmini & goto ERROR)
copy %REPO_ROOT%\driver\net\ndis\imxnetmini\imxnetmini.wm.xml %DRVR_ROOT%\Net\ >NUL

mkdir %DRVR_ROOT%\UART >NUL 2>NUL
copy %BUILD_ROOT%\imxuart\* %DRVR_ROOT%\UART\ >NUL
if errorlevel 1 (set FAILURE=imxuart & goto ERROR)
copy %REPO_ROOT%\driver\serial\imxuart\imxuart.wm.xml %DRVR_ROOT%\UART\ >NUL

mkdir %DRVR_ROOT%\SPI >NUL 2>NUL
copy %BUILD_ROOT%\imxecspi\* %DRVR_ROOT%\SPI\ >NUL
if errorlevel 1 (set FAILURE=imxecspi & goto ERROR)
copy %REPO_ROOT%\driver\spi\imxecspi\imxecspi.wm.xml %DRVR_ROOT%\SPI\ >NUL

mkdir %DRVR_ROOT%\PWM >NUL 2>NUL
copy %BUILD_ROOT%\imxpwm\* %DRVR_ROOT%\PWM\ >NUL
if errorlevel 1 (set FAILURE=imxpwm & goto ERROR)
copy %REPO_ROOT%\driver\pwm\imxpwm\imxpwm.wm.xml %DRVR_ROOT%\PWM\ >NUL

mkdir %DRVR_ROOT%\thermal\sensor >NUL 2>NUL
copy %BUILD_ROOT%\imxtmu\* %DRVR_ROOT%\thermal\sensor >NUL
if errorlevel 1 (set FAILURE=imxtmu & goto ERROR)
copy %REPO_ROOT%\driver\thermal\sensor\imxtmu.wm.xml %DRVR_ROOT%\thermal\sensor >NUL

mkdir %DRVR_ROOT%\thermal\client >NUL 2>NUL
copy %BUILD_ROOT%\imxthermalclient\* %DRVR_ROOT%\thermal\client >NUL
if errorlevel 1 (set FAILURE=imxthermalclient & goto ERROR)
copy %REPO_ROOT%\driver\thermal\client\imxthermalclient.wm.xml %DRVR_ROOT%\thermal\client >NUL

mkdir %DRVR_ROOT%\USDHC >NUL 2>NUL
copy %BUILD_ROOT%\imxusdhc\* %DRVR_ROOT%\USDHC\ >NUL
if errorlevel 1 (set FAILURE=imxusdhc & goto ERROR)
copy %REPO_ROOT%\driver\sd\imxusdhc\imxusdhc.wm.xml %DRVR_ROOT%\USDHC\ >NUL

mkdir %DRVR_ROOT%\OPTEE >NUL 2>NUL
copy %BUILD_ROOT%\OpteeTrEE\* %DRVR_ROOT%\OPTEE\ >NUL
if errorlevel 1 (set FAILURE=OpteeTrEE & goto ERROR)
copy %REPO_ROOT%\driver\TrEE\TrEE\OpteeTrEE.wm.xml %DRVR_ROOT%\OPTEE\ >NUL

:: Copy VPU stuff
mkdir %DRVR_ROOT%\VPU >NUL 2>NUL
copy %BUILD_ROOT%\imxvpukm\* %DRVR_ROOT%\VPU\ >NUL
if errorlevel 1 (set FAILURE=imxvpukm & goto ERROR)
copy %REPO_ROOT%\driver\video\imxvpukm\imxvpukm.wm.xml %DRVR_ROOT%\VPU\ >NUL

copy %BUILD_ROOT%\imxvpumft\imxvpumft.dll %DRVR_ROOT%\VPU\ >NUL
if errorlevel 1 (set FAILURE=imxvpumft & goto ERROR)

copy %BUILD_ROOT%\imxomxg1\imxomxg1.dll %DRVR_ROOT%\VPU\ >NUL
if errorlevel 1 (set FAILURE=imxomxg1 & goto ERROR)

copy %BUILD_ROOT%\imxomxg2\imxomxg2.dll %DRVR_ROOT%\VPU\ >NUL
if errorlevel 1 (set FAILURE=imxomxg2 & goto ERROR)

copy %BUILD_ROOT%\imx-vpu-dwl\imx-vpu-dwl.dll %DRVR_ROOT%\VPU\ >NUL
if errorlevel 1 (set FAILURE=imx-vpu-dwl & goto ERROR)

:: Copy USB
mkdir %DRVR_ROOT%\USB >NUL 2>NUL
copy %BUILD_ROOT%\imxUcmTcpciCxClient\* %DRVR_ROOT%\USB\ >NUL
if errorlevel 1 (set FAILURE=imxUcmTcpciCxClient & goto ERROR)
copy %REPO_ROOT%\driver\USB\imxUcmTcpciCxClient\imxUcmTcpciCxClient.wm.xml %DRVR_ROOT%\USB\ >NUL

:: Copy HAL Extension Packages
echo Copying HAL Extension Packages to %DRVR_ROOT%
mkdir %DRVR_ROOT%\HalExtDma >NUL 2>NUL
copy %BUILD_ROOT%\HalExtiMXDma\* %DRVR_ROOT%\HalExtDma\ >NUL
if errorlevel 1 (set FAILURE=HalExtiMXDma & goto ERROR)
copy %REPO_ROOT%\hals\halext\HalExtiMXDma\HalExtiMXDma.wm.xml %DRVR_ROOT%\HalExtDma\ >NUL

:: Copy Galcore GPU and iMX 8M dispctrl driver
echo Copying Galcore GPU driver to %DRVR_ROOT%
mkdir %DRVR_ROOT%\Galcore >NUL 2>NUL
copy %COMP_ROOT%\Galcore\* %DRVR_ROOT%\Galcore\ >NUL
if errorlevel 1 (set FAILURE=Galcore & goto ERROR)

:: Copy Patch files
echo Copying Drivers to %BINPTCH_ROOT%
mkdir %BINPTCH_ROOT%\Sdport >NUL 2>NUL
copy %COMP_ROOT%\Sdport\* %BINPTCH_ROOT%\Sdport\ >NUL
if errorlevel 1 (set FAILURE=Sdport & goto ERROR)


exit /b 0

:ERROR
echo CreateBSP.bat failed to copy %FAILURE% binaries to the BSP directory! Please ensure that the drivers have built in Visual Studio.
exit /b 1

#
# NXP iMX8M Quad EVK board description
#
# The board is iMX8M with 4GB DRAM
#
#  Copyright (c) 2018, Microsoft Corporation. All rights reserved.
#  Copyright (c) 2013-2018, ARM Limited. All rights reserved.
#  Copyright 2019-2020 NXP
#
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#


################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  DEFINE BOARD_NAME       = MCIMX8M_EVK_4GB
  DEFINE IMX_FAMILY       = IMX8MQ
  DEFINE FIRMWARE_VER     = 2020-02

  PLATFORM_NAME           = iMX8
  PLATFORM_GUID           = F01954EE-8AC4-45BC-80E5-511EAE64C38C
  PLATFORM_VERSION        = 0.1
  DSC_SPECIFICATION       = 0x00010019
  OUTPUT_DIRECTORY        = Build/$(BOARD_NAME)
  SUPPORTED_ARCHITECTURES = AARCH64
  BUILD_TARGETS           = DEBUG|RELEASE
  SKUID_IDENTIFIER        = DEFAULT
  BOARD_DIR               = NXP/$(BOARD_NAME)
  FLASH_DEFINITION        = $(BOARD_DIR)/$(BOARD_NAME).fdf

################################################################################
#
# includes Section - statements common to all iMX8 boards
#
################################################################################


# Include common peripherals
!include iMX8Pkg/iMX8CommonDsc.inc
!if $(CONFIG_FRONTPAGE) == TRUE
!include FrontpageDsc.inc
!endif

################################################################################
#
# Board specific Section - entries specific to this Platform
#
################################################################################
[LibraryClasses.common]
  ArmPlatformLib|$(BOARD_DIR)/Library/iMX8BoardLib/iMX8BoardLib.inf

[Components.common]
  #
  # ACPI Support
  #
  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf
  MdeModulePkg/Universal/Acpi/AcpiPlatformDxe/AcpiPlatformDxe.inf
  $(BOARD_DIR)/AcpiTables/AcpiTables.inf

  #
  # SMBIOS/DMI
  #
  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
  $(BOARD_DIR)/Drivers/SmbiosPlatformDxe/SmbiosPlatformDxe.inf

  #
  # FPDT
  #
  #Enable ReportStatusCodeRouterRuntimeDxe & FirmwarePerformanceDxe for UEFI Performance
  MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  MdeModulePkg/Universal/Acpi/FirmwarePerformanceDataTableDxe/FirmwarePerformanceDxe.inf {
    <LibraryClasses>
      LockBoxLib|MdeModulePkg/Library/LockBoxNullLib/LockBoxNullLib.inf
  }

  #Enable DpApp to visualize UEFI Performance
  ShellPkg/DynamicCommand/DpDynamicCommand/DpApp.inf
################################################################################
#
# Pcd Section - list of all EDK II PCD Entries defined by this Platform
#
################################################################################

[PcdsFeatureFlag.common]
  ## If TRUE, Graphics Output Protocol will be installed on virtual handle created by ConsplitterDxe.
  #  It could be set FALSE to save size.
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutGopSupport|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdTurnOffUsbLegacySupport|TRUE

[PcdsFixedAtBuild.common]
  # FirmwareRevision 0.1
  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareRevision|0x00000001

  # System memory size (4GB)
  # Limit to 3GB of DRAM at the top of the 32bit address space
!if $(CONFIG_OPTEE) == TRUE
  # OpTEE is loaded at top of memory by Arm-TF. Reduce memory size to avoid collision.
  gArmTokenSpaceGuid.PcdSystemMemorySize|0xBE000000
!else
  gArmTokenSpaceGuid.PcdSystemMemorySize|0xC0000000
!endif

# there is 0Gb in the 1Gb bank of memory after top of 32 bit address space
  giMX8TokenSpaceGuid.PcdBank1MemoryBase|0x0000000100000000
  giMX8TokenSpaceGuid.PcdBank1MemorySize|0x0000000000000000

  #
  # NV Storage PCDs. Use base of 0x30370000 for SNVS?
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableBase|0x30370000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize|0x00004000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingBase|0x30374000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize|0x00004000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareBase|0x30378000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareSize|0x00004000

  # i.MX8M Quad
  gArmPlatformTokenSpaceGuid.PcdCoreCount|4
  gArmPlatformTokenSpaceGuid.PcdClusterCount|1

  gArmTokenSpaceGuid.PcdVFPEnabled|1

  #
  # iMXPlatformPkg
  #

  ## iMXPlatformPackage - Serial Terminal
  giMXPlatformTokenSpaceGuid.PcdSerialRegisterBase|0x30860000

  # uSDHCx | iMX8M EVK Connections
  #-------------------------------------
  # uSDHC1 | eMMC
  # uSDHC2 | SD Card slot
  # uSDHC3 | N/A
  # uSDHC4 | N/A
  #
  giMXPlatformTokenSpaceGuid.PcdSdhc1Enable|TRUE
  giMXPlatformTokenSpaceGuid.PcdSdhc2Enable|TRUE
  giMXPlatformTokenSpaceGuid.PcdSdhc3Enable|FALSE
  giMXPlatformTokenSpaceGuid.PcdSdhc4Enable|FALSE

  giMXPlatformTokenSpaceGuid.PcdSdhc1CardDetectSignal|0xFF00
  giMXPlatformTokenSpaceGuid.PcdSdhc1WriteProtectSignal|0xFF00
  giMXPlatformTokenSpaceGuid.PcdSdhc1DeviceType|0x8
  giMXPlatformTokenSpaceGuid.PcdSdhc2CardDetectSignal|0xFF00
  giMXPlatformTokenSpaceGuid.PcdSdhc2WriteProtectSignal|0xFF00
  giMXPlatformTokenSpaceGuid.PcdSdhc2DeviceType|0x1
  giMXPlatformTokenSpaceGuid.PcdSdhc3CardDetectSignal|0xFF00
  giMXPlatformTokenSpaceGuid.PcdSdhc3WriteProtectSignal|0xFF01
  giMXPlatformTokenSpaceGuid.PcdSdhc4CardDetectSignal|0xFF00
  giMXPlatformTokenSpaceGuid.PcdSdhc4WriteProtectSignal|0xFF01

  #
  # PCIe
  #
  # PCIe 1 Host config space is fixed at 0x33800000. The memory range from
  # 0x18000000 - 0x1FFFFFFF is assigned for PCIe 1. The memory layout defined
  # by the boot loader is as below
  #
  # PCIe Device Config0 Space : 0x1FF00000 - 0x1FF7FFFF
  # PCIe Device Config1 Space : 0x18000000 - 0x18FFFFFF
  # PCIe Device Memory Space : 0x19000000 - 0x1FEFFFFF
  giMX8TokenSpaceGuid.PcdPcie1Enable|TRUE
  giMX8TokenSpaceGuid.PcdPcie1ControlBaseAddress|0x33800000
  giMX8TokenSpaceGuid.PcdPcie1DeviceMemoryBase|0x19000000
  giMX8TokenSpaceGuid.PcdPcie1DeviceMemorySize|0x06F00000
  giMX8TokenSpaceGuid.PcdPcie1DeviceConfig0Base|0x1FF00000
  giMX8TokenSpaceGuid.PcdPcie1DeviceConfig0Size|0x00080000
  giMX8TokenSpaceGuid.PcdPcie1SwitchSupport|TRUE
  giMX8TokenSpaceGuid.PcdPcie1DeviceConfig1Base|0x18000000
  giMX8TokenSpaceGuid.PcdPcie1DeviceConfig1Size|0x01000000
  giMX8TokenSpaceGuid.PcdPcie1InternalRefClock|FALSE
  giMX8TokenSpaceGuid.PcdPcie1MaxLinkSpeed|1
  giMX8TokenSpaceGuid.PcdPcie1ResetGpio|TRUE
  giMX8TokenSpaceGuid.PcdPcie1ResetGpioBankNumber|5
  giMX8TokenSpaceGuid.PcdPcie1ResetGpioIoNumber|28
  #
  # PCIe 2 Host config space is fixed at 0x33C00000. The memory range from
  # 0x20000000 - 0x28000000 is assigned for PCIe 2. The memory layout defined
  # by the boot loader is as below
  #
  # PCIe Device Config0 Space : 0x27F00000 - 0x27F7FFFF
  # PCIe Device Config1 Space : 0x20000000 - 0x20FFFFFF
  # PCIe Device Memory Space :  0x21000000 - 0x27EFFFFF
  giMX8TokenSpaceGuid.PcdPcie2Enable|TRUE
  giMX8TokenSpaceGuid.PcdPcie2ControlBaseAddress|0x33C00000
  giMX8TokenSpaceGuid.PcdPcie2DeviceMemoryBase|0x21000000
  giMX8TokenSpaceGuid.PcdPcie2DeviceMemorySize|0x06F00000
  giMX8TokenSpaceGuid.PcdPcie2DeviceConfig0Base|0x27F00000
  giMX8TokenSpaceGuid.PcdPcie2DeviceConfig0Size|0x00080000
  giMX8TokenSpaceGuid.PcdPcie2SwitchSupport|TRUE
  giMX8TokenSpaceGuid.PcdPcie2DeviceConfig1Base|0x20000000
  giMX8TokenSpaceGuid.PcdPcie2DeviceConfig1Size|0x01000000
  giMX8TokenSpaceGuid.PcdPcie2InternalRefClock|FALSE
  giMX8TokenSpaceGuid.PcdPcie2MaxLinkSpeed|1
  giMX8TokenSpaceGuid.PcdPcie2ResetGpio|TRUE
  giMX8TokenSpaceGuid.PcdPcie2ResetGpioBankNumber|5
  giMX8TokenSpaceGuid.PcdPcie2ResetGpioIoNumber|12

  ## SBSA Watchdog Count
!ifndef DISABLE_SBSA_WATCHDOG
  gArmPlatformTokenSpaceGuid.PcdWatchdogCount|2
!endif

  #
  # ARM Generic Interrupt Controller
  #
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x38800000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x38880000

!if TRUE == FALSE
  #
  # Watchdog
  #
  gArmTokenSpaceGuid.PcdGenericWatchdogControlBase|0x30280000
#  gArmTokenSpaceGuid.PcdGenericWatchdogRefreshBase| *** unused ***
  gArmTokenSpaceGuid.PcdGenericWatchdogEl2IntrNum|110
!endif

  #
  # ARM Architectural Timer Frequency
  #
  gEmbeddedTokenSpaceGuid.PcdMetronomeTickPeriod|1000

  gEfiMdeModulePkgTokenSpaceGuid.PcdResetOnMemoryTypeInformationChange|FALSE

  #
  # SMBIOS entry point version
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdSmbiosVersion|0x0300
  gEfiMdeModulePkgTokenSpaceGuid.PcdSmbiosDocRev|0x0

  giMX8TokenSpaceGuid.PcdGpuEnable|TRUE

[PcdsPatchableInModule]
  # Use system default resolution
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|0

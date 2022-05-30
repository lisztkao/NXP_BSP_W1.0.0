BSP change history
====
This chapter lists changes in releases, including new features and defect fixes.

## 1/2022 : W0.9.0
Private preview release for i.MX8M platform.
  - Supported boards:
    :   The existing BSP with support for MCIMX8M-EVK NXP board.

## 3/2022 : W0.9.1
Public preview release for i.MX8M platform.
  - Fixes:
      - eMMC driver:
        :   eMMC tuning parameters add to the Dsdt-Sdhc.asl.
      - BSP deployment:
        :   Removed invalid characters from make-winpe-enterprise.cmd.

## 4/2022 : W1.0.0
Public release for i.MX8M and i.MX8M Mini platforms.
  - Supported boards:
    :   MCIMX8M-EVK evaluation kit
    :   8MMINILPD4-EVK evaluation kit
  - New features:
      - VPU driver:
	:   Supported codes HEVC, VP9, H.264, VP8. MPEG-2 and MPEG-4 codes supported on i.MX8M only.
  - Fixes:
      - UART driver:
        :   The UART driver failure during uninstallation in the Device manager has been fixed.
      - I2C driver:
        :   The issue in iMXI2cRead function (when ReadBufferSize == 1) in UEFI has been fixed.
      -  buildme 64.sh:
        :   The script has been updated. Updates in UEFI source code were included in firmware.bin only if firmware was built with -c parameter (clean build).
      -  PCIe:
        :   PCIE ATU (Address Translation Unit) setup for PCIE BAR memory mapped registers in UEFI drivers has been fixed. After this fix, the system works as expected in UEFI and relevant Storage drivers appears in Windows.

Building Windows 10 IoT for NXP i.MX Processors {#build-bsp}
====

## Obtaining BSP sources

### Required Tools
The following tools are required to follow this chapter:
  - git
  - git-lfs
  - software to unpack zip, gzip and tar archives

### The NXP i.MX Windows IoT BSP source package

The Windows IoT BSP for NXP i.MX Processors consists of multiple parts, namely:
 1) The NXP i.MX BSP sources package which is available at www.NXP.com. Package contains sources for both the boot firmware and Windows drivers.
 2) The iMX firmware and NXP Code Signing Tool (CST) available at www.NXP.com.
 3) Open-source parts of boot firmware and tools that are not distributed as part NXP BSP package.
 4) The Windows IOT Enterprise operating system provided by Microsoft.

To prepare sources for building BSP follow these steps:

> Note Only steps 1-3 are required for building Windows drivers from source. All steps are required for building firmware from source.

 1) Download the NXP i.MX BSP provided as `W<os_version>-imx-windows-bsp-<build_date>.zip` archive from www.NXP.com.

 2) Create an empty directory, further referred as `<BSP_DIR>`, and extract the downloaded archive there.
    Path to this directory should be short as possible containing only letters and underscores, braces and other special characters could cause build errors.

    Shell command `unzip W<os_version>-imx-windows-bsp-<build_date>.zip -d win10-iot-bsp` command can be used to extract the package.
    Command will create `win10-iot-bsp` directory containing `.git` repository with the BSP release.

 3) Populate the directory by running `Init.bat`, to build drivers on Windows host, `Init.sh`, to build firmware on Linux host.
    Both scripts will checkout sources from the repository by `git reset --hard`. The `Init.sh` shall also checkout submodules that are required to build i.MX boot firmware by `git submodule update --init --recursive`.
    During prerelease testing the `Init.sh` executed inside Ubuntu environment run into "server certificate verification failed. CAfile: /etc/ssl/certs/ca-certificates.crt CRLfile: none" error.
    Problem could be solved by installing `apt-transport-https` `ca-certificates` and certificate update.

    ```bash
    sudo apt update ; sudo apt-get install apt-transport-https ca-certificates -y ; sudo update-ca-certificates
    ```
 4) At this point it is possible to build the Windows drivers. Further steps are required only to build i.MX boot firmware (ATF, U-boot and UEFI) from sources.

 5) Download and extract the [Code Signing Tools (CST)](https://www.nxp.com/webapp/sps/download/license.jsp?colCode=IMX_CST_TOOL) from NXP's website.
    You will need to create an account on NXP's website to access this tool.
    Extract the tool inside bsp repository, and rename the newly created folder to cst to get `<BSP_DIR>/cst` folder:

    ```bash
    tar xf cst-3.1.0.tgz
    mv release cst
    rm cst-3.1.0.tgz
    ```

 6) Download and extract the [iMX firmware](https://www.nxp.com/lgfiles/NMG/MAD/YOCTO/firmware-imx-8.3.bin) from NXP's website and place it to firmware-imx.
    Extract the tool inside bsp repository, and rename the newly created folder to `firmware-imx` to get `<BSP_DIR>/firmware-imx/firmware/ddr/` in directory tree:

    ```bash
    chmod +x firmware-imx-8.3.bin
    ./firmware-imx-8.3.bin
    mv firmware-imx-8.3 firmware-imx
    rm firmware-imx-8.3.bin
    ```

 7) At this point your directory structure should contain the following folders.

    ```
    - <BSP_DIR>
       |- cst (manually downloaded)
       |- firmware-imx (manually downloaded)
       |- Documentation
       |- MSRSec
       |- RIoT
       |- imx-atf
       |- imx-mkimage
       |- imx-optee-os
       |- imx-windows-iot
       |- mu_platform_nxp
       |- patches
       |- uboot-imx
    ```

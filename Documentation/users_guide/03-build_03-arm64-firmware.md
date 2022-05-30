Building ARM64 Firmware {#build-arm64-firmware}
----

This chapter describes the process of setting up a build-environment to build the latest firmware and update the firmware on development board.

### Setting up your build environment

 1. Start Linux environment such as:
      * Dedicated Linux system
      * Linux Virtual Machine
      * Windows Subsystem for Linux ([WSL setup instructions](https://docs.microsoft.com/en-us/windows/wsl/install-win10))
        
        > Note: W<os_version>-imx-windows-bsp-<build_date>.zip was validated with Ubuntu 20.04 in WSL and also standalone Ubuntu.

 2. Obtain and prepare the BSP sources by following all steps described in [Obtaining BSP sources][]. Use `Init.sh` not `Init.bat` to populate the repository and all submodules.

 3. Install or update build tools. The shell commands bellow can be used to do this process on Ubuntu 20.04 or 18.04.
     1. Update package manager.
     
        ```bash
        sudo apt-get update
        sudo apt-get upgrade
        ```
    
     2. If using Ubuntu 18.04 and possibly other older distributions the mono package might be outdated.
        Causing build to fail. For such distributions add mono repository to the system as described in [https://www.mono-project.com/download/stable/#download-lin](https://www.mono-project.com/download/stable/#download-lin) before installing the mono package.
        
        The process valid for Ubuntu 18.04 in December 2021:
        
        ```bash
        sudo apt install gnupg ca-certificates
        sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
        # Optionally key could be downloaded to a file and added manually by 'apt-key add <keyfile>'.
        # Now that certificate is installed we can add official mono repository to repository list.
        echo "deb https://download.mono-project.com/repo/ubuntu stable-bionic main" | sudo tee /etc/apt/sources.list.d/mono-official-stable.list
        sudo apt update
        ```
    
     3. Install required software. Note the mu_project currently requires python 3.8 and higher.
        
        ```bash
        sudo apt-get install attr build-essential python3.8 python3.8-dev python3.8-venv device-tree-compiler bison flex swig iasl uuid-dev wget git bc libssl-dev zlib1g-dev python3-pip mono-devel gawk
        ```
    
     4. Download the Arm64 cross-compiler.
        
        ```bash
        pushd ~
        wget https://releases.linaro.org/components/toolchain/binaries/7.4-2019.02/aarch64-linux-gnu/gcc-linaro-7.4.1-2019.02-x86_64_aarch64-linux-gnu.tar.xz
        tar xf gcc-linaro-7.4.1-2019.02-x86_64_aarch64-linux-gnu.tar.xz
        rm gcc-linaro-7.4.1-2019.02-x86_64_aarch64-linux-gnu.tar.xz
        # The cross compiler prefix is required to be exported later into AARCH64_TOOLCHAIN_PATH variable.
        # export AARCH64_TOOLCHAIN_PATH=~/gcc-linaro-7.4.1-2019.02-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
        popd
        ```
     
     5. Change directory to the BSP_DIR. Following commands reference the files inside the BSP directory. That BSP_DIR contains extracted W<os_version>-imx-windows-bsp-<build_date>.zip.
        
        ```bash
        cd <BSP_DIR>
        ```
    
     6. [Project MU](https://microsoft.github.io/mu/CodeDevelopment/prerequisites/#all-operating-systems-python-virtual-environment-and-pytools)
        strongly suggests use of Python Virtual Environment for each workspace - in this case BSP revision.
        Separated environments allow workspaces to keep specific Pip module versions without modifying global system state when firmware is compiled.

        Note The virtual environment doesn't use system packages. Thus `sudo` must not be used when installing packages using pip.
        
        ```bash
        python3.8 -m venv <path to new environment>
        source <path to new environment>/bin/activate
        eg.:
        python3.8 -m venv ~/venv/win_fw_build
        source ~/venv/win_fw_build/bin/activate
        ```
        
        Please note the path to the new environment you chosen. Environment has to be activated before building the firmware.
        
     7. Install required python packages.
         1) Install or update mu_platform Python dependencies using pip.
            
            ```bash
            pushd mu_platform_nxp
            pip3 install -r requirements.txt --upgrade
            ```
         2) Install pycryptodome package (successor of pycrypto).
            
            ```bash
            pip3 install pycryptodome
            ```
         3) Install pyelftools package. 
         
            ```bash
            pip3 install pyelftools
            ```
                        
     8. Setup Mu platform. (Optional because buildme64.sh does these steps automatically.)
         1) Setup and update submodules.
         
            ```bash
            python3 NXP/MCIMX8M_EVK_4GB/PlatformBuild.py --setup
            # or NXP/MCIMX8M_MINI_EVK_2GB/PlatformBuild.py
            ```
            In case you return here facing problems during UEFI build, use `--force` to clean the environment.
            Make sure to commit or stash all your changes first, `--force` argument performs git reset --hard.
         2) Initialize and update Mu platform dependencies.
            If this command fails try upgrading mono.
            The best way to do this is to uninstall mono and reinstall if from its official repository.
            Process is described at [https://www.mono-project.com/download/stable/#download-lin](https://www.mono-project.com/download/stable/#download-lin).
            
            ```bash
            python3 NXP/MCIMX8M_EVK_4GB/PlatformBuild.py --update
            # or NXP/MCIMX8M_MINI_EVK_2GB/PlatformBuild.py
            ```
     9. Return to BSP root.
     
        ```bash
        popd
        ```

### Building the firmware

This chapter assumes the BSP sources have been prepared as described in [Obtaining BSP sources][] chapter.

To build the boot firmware:
 1. Open cmd prompt at BSP_DIR.
        
    ```bash
    cd <BSP_DIR>
    ```
      
 2. Activate your python virtual environment created in [][Setting up your build environment]. (Use the path specified when creating the environment.)
 
    ```bash
    source ~/venv/win_fw_build/bin/activate
    ```
 3. Export AARCH64_TOOLCHAIN_PATH cross compiler prefix.
    In this guide toolchain has been placed inside home (~/) drectory.
 
    ```bash
    export AARCH64_TOOLCHAIN_PATH=~/gcc-linaro-7.4.1-2019.02-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
    ```

 5. Optionally, in case of major update, you may need to step into mu_platform_nxp and run `python3 NXP/MCIMX8M_EVK_4GB/PlatformBuild.py` with `--setup --force` and then `--update` manually.
    To get clean and up-to-date MU build environment.
    Make sure to stash or commit your changes. Command performs `git reset --hard`.
    
 6. Build the firmware and create firmware.bin. To build the boot firmware execute the `buildme64.sh -b <BOARD_NAME> -t all [-clean] -fw` script provided in BSP_DIR (the root of extracted BSP sources).
    
    The `buildme64.sh` script bundled in BSP also copies `flash.bin` and `uefi.fit` into `<BSP_DIR>/imx-windows-iot/components/Arm64BootFirmware/<board_name>`.
    This allows to rebuild only UEFI or U-boot.
 
    ```bash
    ./buildme64.sh -b NXPEVK_iMX8M_4GB -t all -c -fw
    ```
      - Use `-b NXPEVK_iMX8M_4GB` or `-b 8M` to select i.MX 8M EVK
      - Use `-b NXPEVK_iMX8M_Mini_2GB` or `-b 8Mm` to select i.MX 8M Mini EVK
      - Use `-t all -t sign_images` to build signed_firmware.bin
 
 7. To deploy `firmware.bin` to the i.MX development board follow the process described in [Deploy boot firmware][].

### Common causes of build errors:
 1. ImportError: No module named Crypto.PublicKey.
    - This error is encountered when pycryptodome module is missing. Or in case obsolete pycrypto needs to be removed.
 2. Unable to enter directory. Directory doesn't exist.
    - We have run into this problem in case gitmodules were not downloaded completely (eg. MSRSec is empty) or `cst` or `firmware` directories are missing. Try repeating the [Obtaining BSP sources][] step by step.
 3. The build fails in WSL while the BSP is located somewhere in `/mnt/c` of the WSL.
    - Try `setfattr -n system.wsl_case_sensitive -v 1 <BSP_DIR>`. OP-Tee also requires symbolic links. We have been able to build boot firmware in `/mnt/c/` on Windows OS version 1909. Workaround is to copy the BSP to WSL filesystem eg. to HOME.
 4. RuntimeError: SDE is not current. Please update your env before running this tool.
      - Try to update mono_devel package and repeat setup and update steps for PlatformBuild.py in [Setting up your build environment][].
 5. cp: cannot stat '../../firmware-imx/firmware/ddr/synopsys/lpddr4_pmu_train_*.bin'
      - Please make sure the firmware-imx obtained in [Obtaining BSP sources][] chapter is placed inside the BSP in way the following directories exist `<BSP_DIR>/firmware-imx/firmware/ddr/synopsys`.
 6. Can't find elftools module. Probably it is not installed on your system.
    You can install this module with apt install python3-pyelftools.
      - This error means the `pyelftools` module is not installed inside of the python environment. To install this package into environment use `pip3 install pyelftools` without `sudo`.

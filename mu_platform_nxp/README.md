# Welcome to [Project MU](https://microsoft.github.io/mu/)

## &#x1F539; Copyright
Copyright (c) 2017, Microsoft Corporation

All rights reserved. Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## About

This document provides a brief introduction to Project MU as well as information about building a UEFI image for the iMX8. There's more to booting an iMX8 than UEFI; additional documentation for those steps is provided [here](https://github.com/ms-iot/imx-iotcore/blob/public_preview/Documentation/build-arm64-firmware.md).


## Building with MU TL;DR

1. Install all tools and dependencies.
2. Run `python {Platform}/{Device}/PlatformBuild.py --setup` to grab all current code. Add `--force` to clean environment as well.
3. Run `python {Platform}/{Device}/PlatformBuild.py --update` to set up the build environment.
4. Run `python {Platform}/{Device}/PlatformBuild.py` to invoke the build process.

# MU Repos

## NXP Platform

This is platform repo, which is the root repository in which all the other submodules are located. This is also where code specific to the platform or devices would be located, including `PlatformBuild.py`.

## [Silicon/ARM/NXP](https://github.com/ms-iot/MU_SILICON_NXP.git)

Silicon code provided from a manufacturer is kept in its own submodule so it can be maintained seperately from platform code.

## [MU_BASECORE](https://microsoft.github.io/mu/dyn/mu_basecore/RepoDetails/)

This is the main repo. Contains the guts of the build system as well as core UEFI code, forked from TianoCore.

## [Silicon/ARM/MU_TIANO](https://microsoft.github.io/mu/dyn/mu_silicon_arm_tiano/RepoDetails/)

Silicon code from TianoCore has been broken out into indivudal submodules. iMX8 is ARM, so we need this submodule. An Intel project would include [Intel/MU_TIANO](https://microsoft.github.io/mu/dyn/mu_silicon_intel_tiano/RepoDetails/).

## [Common/MU_TIANO](https://microsoft.github.io/mu/dyn/mu_tiano_plus/RepoDetails/)

Additional, optional libraries and tools forked from TianoCore.

## [Common/MU](https://microsoft.github.io/mu/dyn/mu_plus/RepoDetails/)

Additional, optional libraries and tools we've added to make MU great!

## [Common/MU_OEM_SAMPLE](https://microsoft.github.io/mu/dyn/mu_tiano_plus/RepoDetails/)

This module is a sample implementation of a FrontPage and several BDS support libraries. This module is intended to be forked and customized.

# Build Environment

Part of Project Mu is moving towards a fully Python build environment. We currently have three published Python modules, using pip, that encompass setting up the build environment, logging, and running CI builds.

Documentation of the build system is still in progress on the [Project MU](https://microsoft.github.io/mu/) page under Code Repositories.

## Troubleshooting

To forcibly install the latest version of mu_environment:
`pip install --upgrade -r requirements.txt`

Since mu_environment has a dependency on mu_python_library, it should be updated through this command as well. If they are not, the same command can be run for mu_python_library.

# Get Tools and Dependencies

- Install latest Mono
    - `sudo apt install gnupg ca-certificates`
    - `sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF`
    - `echo "deb https://download.mono-project.com/repo/ubuntu stable-bionic main" | sudo tee /etc/apt/sources.list.d/mono-official-stable.list`
    - `sudo apt update`
- `sudo apt-get install gcc g++ make python3 python3-pip git mono-devel`
    - Minimum Python version is 3.6
    - Minimum git version 2.11

# Get and Build Code (Older Process)

- `git clone https://github.com/ms-iot/MU_PLATFORM_NXP`
- Install pip modules for build:
    - `pip3 install -r requirements.txt --upgrade`
- Download [Linaro AARCH 64 GCC 7.2.1](https://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/aarch64-linux-gnu/)
    - Set GCC5_AARCH64_PREFIX to this path
        - `tar -xf gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu.tar.gz`
        - `export GCC5_AARCH64_PREFIX=$PWD/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-`
- `python3 NXP/MCIMX8M_EVK_4GB/PlatformBuild.py --setup`
    - This fetches any dependencies via NuGet and synchronizes submodules
- `rm -r Build; rm -r Conf; python3 NXP/MCIMX8M_EVK_4GB/PlatformBuild.py TOOL_CHAIN_TAG=GCC5 BUILDREPORTING=TRUE BUILDREPORT_TYPES="PCD"`
    - Removing Build and Conf directories ensures that you aren't accidentally keeping around configuration files and autogen build files that need to be updated.
    - Specify the `TOOL_CHAIN_TAG` either here or in `NXP/Conf/Target.template.ms`
    - Build reports are placed in the `Build` folder on a successful build and contain a complete list of every module that was built and what the PCDs were set to.

# Serial Output
- [User Guide NXP](https://www.nxp.com/docs/en/user-guide/IMX8MQUADEVKQSG.pdf)
- [In Depth Guide NXP](https://www.nxp.com/support/developer-resources/software-development-tools/i.mx-developer-resources/evaluation-kit-for-the-i.mx-8m-applications-processor:MCIMX8M-EVK?tab=In-Depth_Tab)
- The [drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) that actually worked for me
- Serial configuration
    - Speed = 921600
    - Data bits = 8
    - Stop bits = 1
    - Parity = None
    - Flow Control = XON/XOFF

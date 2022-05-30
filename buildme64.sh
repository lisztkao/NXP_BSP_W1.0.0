#!/bin/bash
# 
# Copyright 2020 NXP 
# All rights reserved. 
#  
# Redistribution and use in source and binary forms, with or without modification, 
# are permitted provided that the following conditions are met: 
#
# Redistributions of source code must retain the above copyright notice, this list 
# of conditions and the following disclaimer. 
#
# Redistributions in binary form must reproduce the above copyright notice, this 
# list of conditions and the following disclaimer in the documentation and/or 
# other materials provided with the distribution. 
#
# Neither the name of the copyright holder nor the names of its 
# contributors may be used to endorse or promote products derived from this 
# software without specific prior written permission. 
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR 
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
# 


# File contents:
#
# 1. help string
# 2. enabled features list
# 3. argument check
# 4. arguments to feature list processing
# 5. high assurance boot helper functions
# 6. build board
# 7. main
#   1. echo selected configuration
#   2. for each enabled board:
#       - set environment vars for board selected
#       - call build_board()

# 1. help string
usage() { echo "Usage: $0 [-b BOARD_1] [-b BOARD_2] [-t TARGET_1] .. [-c]"        1>&2
          echo ""                                                                 1>&2
          echo "Description:          "                                           1>&2
          echo "          [-b|-board]"                                            1>&2
          echo "            { all,"                                               1>&2
          echo "              8M, NXPEVK_iMX8M_4GB,"                              1>&2
          echo "              8Mm, NXPEVK_iMX8M_Mini_2GB"                         1>&2
          echo "              8Mn, EVK_iMX8MN_2GB }"                              1>&2
          echo ""                                                                 1>&2
          echo "          [-t|-target_app] "                                      1>&2
          echo "            { all, u|uboot, optee, apps|tee_apps,"                1>&2
          echo "              uimg|uboot_image, tools|uefi_tools, uefi,"          1>&2
          echo "              secured_efi|secured_uefi, s|sign_images }"          1>&2
          echo ""                                                                 1>&2
          echo "          [-fw|-fw_bin]"                                          1>&2
          echo "          [-c|-clean]"                                            1>&2
          echo "          [-nu|-no_uuu]"                                          1>&2
          echo "          [-h|-help]"                                             1>&2
          echo "          [-bc|build_configuration]"                              1>&2
          echo "            { release|RELEASE - for Release version of uefi,"     1>&2
          echo "              debug|DEBUG     - for Debug version of uefi }"      1>&2
          echo ""                                                                 1>&2
          echo "Environment variables:          "                                 1>&2
          echo "          [TARGET_WINDOWS_BSP_DIR] - Path to imx-windows-iot,"    1>&2
          echo "               in which the firmware shall be updated."           1>&2
          echo "------------------------------------------------------------"     1>&2 ;
          exit 1; }


# 2. enabled features list
# features are enabled later by script parameters

script_name=$0
build_8m=0
build_8m_mini=0
build_8m_nano=0

clean=0
build_uboot=0
build_atf=0
build_optee=0
build_tee_apps=0
build_uboot_image=0
build_uefi_tools=0
build_uefi=0
build_sign_images=0
build_fw_monolith=0

build_all_selected=0
build_configuration=RELEASE
build_uboot_with_uuu_support=1
build_uefi_profile=DEV

# 3. argument check
# prints help if no arguments

if [ $# -eq 0 ]; then
    echo No arguments specified.
    usage
    exit 0
fi

# 4. arguments to feature list processing
# process arguments one by one in switch-case using shift
#
# variables:
#   - #$
#       - number of arguments left
#   - $1
#       - first argument:   name  (ie. -t    in '-t uboot')
#   - $2
#       - second argument:  value (eg. uboot in '-t uboot')

while test $# -gt 0
do
    case "$1" in

    -c|-clean)
        clean=1
        ;;
    -h|-help)
        usage
        ;;
    -nu|-no_uuu)
        build_uboot_with_uuu_support=0
        ;;
    -fw|-fw_bin)
        build_fw_monolith=1
        ;;
    -t|-target_app)
        case "${2}" in
            u|uboot)
                build_uboot=1
                ;;
            atf)
                build_atf=1
                ;;
            tee|optee)
                build_optee=1
                ;;
            apps|tee_apps)
                build_optee=1
                build_tee_apps=1
                ;;
            uimg|uboot_image)
                build_atf=1
                build_uboot=1
                build_optee=1
                build_uboot_image=1
                ;;
            tools|uefi_tools)
                build_uefi_tools=1
                ;;
            efi|uefi)
                build_uefi=1
                ;;
            secured_efi|secured_uefi)
                build_uefi_profile=SECURE
                ;;
            s|sign_images)
                build_sign_images=1
                ;;
            all)
                build_all_selected=1
                build_uboot=1
                build_atf=1
                build_optee=1
                build_tee_apps=1
                build_uboot_image=1
                build_uefi_tools=1
                build_uefi=1
                build_fw_monolith=1
                ;;
            *)
                echo "Unknown option ${2} specified for -b --build" 
                usage
                ;;
        esac
        shift
        ;;
    -b|-board)
        case "${2}" in
            8M|NXPEVK_iMX8M_4GB)
                build_8m=1
                ;;
            8Mm|NXPEVK_iMX8M_Mini_2GB)
                build_8m_mini=1
                ;;
            8Mn|EVK_iMX8MN_2GB)
                build_8m_nano=1
                ;;
            all)
                build_8m=1
                build_8m_mini=1
                build_8m_nano=1
                ;;
            *)
                echo "Unknown option ${2} specified for -b --build" 
                usage
                ;;
        esac
        shift
        ;;
    -bc|build_configuration)
        case "${2}" in
            release|RELEASE)
                build_configuration=RELEASE
                ;;
            debug|DEBUG)
                build_configuration=DEBUG
                ;;
            *)
            echo "Unknown option ${2} specified for -v"
            usage
            ;;
        esac
        shift
        ;;
    *)
        echo "Unknown option ${1} specified"
        usage
        ;;
    esac
    shift
done

# 5. high assurance boot helper functions

export IMX8_REPO_ROOT=$(pwd)
export CST_ROOT=$IMX8_REPO_ROOT/cst
export KEY_ROOT=$IMX8_REPO_ROOT/imx-windows-iot/build/firmware/test_keys_no_security
export MKIMAGE_WORK_DIR=$IMX8_REPO_ROOT/imx-mkimage/iMX8M
export SRKH_FUSE_BIN=$KEY_ROOT/crts/SRK_1_2_3_4_fuse.bin

if [ $build_uboot_image -eq 1 ]; then
    FILE=firmware-imx
    if ! [ -e "$FILE" ]; then
        echo "ERROR: $FILE directory does not exist. Download and extract the iMX firmware from NXP’s website and place it to firmware-imx. See i.MX_Win10_User's_Guide.pdf for instruction how to install required SW."
        exit
    fi
fi

if [ $build_sign_images -eq 1 ]; then
    FILE=cst
    if ! [ -e "$FILE" ]; then
        echo "ERROR: $FILE directory does not exist. Download and extract the Code Signing Tools (CST) from NXP’s website. See i.MX_Win10_User's_Guide.pdf for instruction how to install required SW."
        exit
    fi
fi

# Requires paths to spl_uboot.log and firmware binary as parameters.
generate_spl_csf () {
    awk -v binary_path="$2" -v indentation=4 '/spl hab block/ { printf "%*sBlocks = %s %s %s \"%s\"\n", indentation, "", $4, $5, $6, binary_path }' $1 \
        | cat $IMX8_REPO_ROOT/imx-windows-iot/build/firmware/csf_templates/mx8/csf_spl.txt.template - \
        | sed -e "s#{KEY_ROOT}#$KEY_ROOT#g" > $MKIMAGE_WORK_DIR/csf_spl.txt
    $CST_ROOT/linux64/bin/cst --o $MKIMAGE_WORK_DIR/csf_spl.bin --i $MKIMAGE_WORK_DIR/csf_spl.txt
}

# Requires paths to spl_uboot.log, fit_hab.log, and firmware binary as parameters.
generate_fit_csf () {
    { \
        awk -v binary_path="$3" -v indentation=4 \
                        '/sld hab block/ { printf "%*sBlocks = 0x%08x 0x%06x 0x%05x \"%s\"", indentation, "", strtonum($4), strtonum($5), strtonum($6), binary_path }' $1 \
        && awk -v binary_path="$3" -v indentation=12 'BEGIN { ORS="" } \
                        /print_fit_hab/ { x=NR+4;next}  (NR<=x) { printf ", \\\n%*s 0x%08x 0x%06x 0x%05x \"%s\"", indentation, "", strtonum($1), strtonum($2), strtonum($3), binary_path }' $2 \
        && echo ;
    } \
        | cat $IMX8_REPO_ROOT/imx-windows-iot/build/firmware/csf_templates/mx8/csf_fit.txt.template - \
        | sed -e "s#{KEY_ROOT}#$KEY_ROOT#g" > $MKIMAGE_WORK_DIR/csf_fit.txt
    $CST_ROOT/linux64/bin/cst --o $MKIMAGE_WORK_DIR/csf_fit.bin --i $MKIMAGE_WORK_DIR/csf_fit.txt
}

# Requires paths to UEFI firmware binary as parameter.
generate_uefi_csf () {
    cat $IMX8_REPO_ROOT/imx-windows-iot/build/firmware/csf_templates/mx8/csf_uefi.txt.template \
        | sed -e "s#{KEY_ROOT}#$KEY_ROOT#g" > csf_uefi.txt
    UEFI_SIZE=$(stat --printf=%s $1) ;\
    INDENTATION=4 ;\
    printf "%*sBlocks = 0x40480000 0x00000 0x%x \"$1\"\n" $INDENTATION "" $UEFI_SIZE >> csf_uefi.txt
}

# Requires paths to spl_uboot.log and u-boot firmware binary as parameters.
sign_uboot_binary () {
    SIGNED_UBOOT_BIN=$(dirname $2)/signed_$(basename $2) ;\
    cp $2 $SIGNED_UBOOT_BIN ;\
    SPL_CSF_OFF=$(awk '/ csf_off/ { print $2 }' $1) ;\
    FIT_CSF_OFF=$(awk '/ sld_csf_off/ { print $2 }' $1) ;\
    dd if=$MKIMAGE_WORK_DIR/csf_spl.bin of=$SIGNED_UBOOT_BIN seek=$(printf '%d' $SPL_CSF_OFF) bs=1 conv=notrunc ;\
    dd if=$MKIMAGE_WORK_DIR/csf_fit.bin of=$SIGNED_UBOOT_BIN seek=$(printf '%d' $FIT_CSF_OFF) bs=1 conv=notrunc
}

# Requires UEFI size as parameters.
generate_ivt_for_uefi () {
    cat $IMX8_REPO_ROOT/imx-windows-iot/build/firmware/csf_templates/mx8/genIVT-template.pl | sed -e "s#{UEFI_PADDED_SIZE}#$1#g" > genIVT.pl
    perl genIVT.pl
}

# Requires paths to UEFI firmware binary as parameter.
sign_uefi_binary () {
    SIGNED_UEFI_BIN=$(dirname $1)/signed_$(basename $1) ;\
    cp $1 $SIGNED_UEFI_BIN ;\
    UEFI_SIZE=$(stat --printf=%s $SIGNED_UEFI_BIN) ;\
    UEFI_PADDED_SIZE=$(printf "0x%x" $(( ( $UEFI_SIZE + 0xfff ) & ~0xfff ))) ;\
    objcopy -I binary -O binary --pad-to $UEFI_PADDED_SIZE --gap-fill=0x00 $SIGNED_UEFI_BIN ;\
    generate_ivt_for_uefi $UEFI_PADDED_SIZE ;\
    cat ivt.bin >> $SIGNED_UEFI_BIN ;\
    generate_uefi_csf $SIGNED_UEFI_BIN ;\
    $CST_ROOT/linux64/bin/cst -i csf_uefi.txt -o csf_uefi.bin ;\
    cat csf_uefi.bin >> $SIGNED_UEFI_BIN
}

# Requires path to u-boot config file as a parameter.
update_srkh_in_uboot_config () {
    SRKH_VALUES=$(hexdump -e '/4 "0x"' -e '/4 "%X""\n"' $SRKH_FUSE_BIN) ; SRKH_VALUES=$(echo -n $SRKH_VALUES) ;\
    tmpfile=$(mktemp) ;\
    cp $1 $tmpfile ;\
    sed 's/\<CONFIG_SPL_HAB_SRKH\>/<\0>/' $tmpfile \
        | awk -v config_value="$SRKH_VALUES" 'BEGIN { config_line = "CONFIG_SPL_HAB_SRKH=\"" config_value "\""} \
            /<CONFIG_SPL_HAB_SRKH>/ { print config_line ; pattern_found = 1 ; next } \
            { print } \
            END { if (!pattern_found) { print config_line } }' > $1 ;\
    rm $tmpfile
}

# 6. definition of build board function

build_board () {
    if [ -z "$AARCH64_TOOLCHAIN_PATH" ] ; then
        echo "AARCH64_TOOLCHAIN_PATH is not set."
        echo "Example: export AARCH64_TOOLCHAIN_PATH=~/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-"
        exit
    fi

    # Prepare env vars
    export CROSS_COMPILE=$AARCH64_TOOLCHAIN_PATH
    export CROSS_COMPILE64=$AARCH64_TOOLCHAIN_PATH
    export GCC5_AARCH64_PREFIX=$AARCH64_TOOLCHAIN_PATH
    export ARCH=arm64

    if [ -d "$TARGET_WINDOWS_BSP_DIR/components/Arm64BootFirmware" ]; then
        TARGET_WINDOWS_BSP_PREFIX=$TARGET_WINDOWS_BSP_DIR
    else
        TARGET_WINDOWS_BSP_PREFIX=imx-windows-iot
    fi
    TARGET_FIRMWARE_COMPONENTS_DIR="${TARGET_WINDOWS_BSP_PREFIX}/components/Arm64BootFirmware/$bsp_folder" # eg. imx-windows-iot/components/Arm64BootFirmware/NXPEVK_iMX8M_4GB
    TARGET_FIRMWARE_DIR="${TARGET_WINDOWS_BSP_PREFIX}/BSP/firmware/$bsp_folder" # eg. imx-windows-iot/BSP/firmware/NXPEVK_iMX8M_4GB

    if [ $build_uboot -eq 1 ]; then
        pushd uboot-imx/ || exit $?
        if [ $clean -eq 1 ]; then
            make distclean
            make clean
        fi
        make $uboot_defconfig || exit $?
        make -s -j2 || exit $?
        popd
    fi

    if [ $build_atf -eq 1 ]; then
        pushd imx-atf || exit $?
        if [ $clean -eq 1 ]; then
            make PLAT=$atf_plat clean || exit $?
        fi
        make -s PLAT=$atf_plat SPD=opteed bl31 || exit $?
        popd
    fi

    if [ $build_optee -eq 1 ]; then
        export -n CROSS_COMPILE
        export -n ARCH
        pushd imx-optee-os || exit $?
        if [ $clean -eq 1 ]; then
            make clean PLATFORM=imx PLATFORM_FLAVOR=$optee_plat || exit $?
            rm -f ./out/arm-plat-imx/tee.bin
        fi
        make -s -j2 PLATFORM=imx PLATFORM_FLAVOR=$optee_plat CFG_TEE_CORE_DEBUG=n CFG_TEE_CORE_LOG_LEVEL=2 CFG_RPMB_FS=y CFG_RPMB_TESTKEY=y CFG_RPMB_WRITE_KEY=y CFG_REE_FS=n CFG_IMXCRYPT=y CFG_CORE_HEAP_SIZE=131072 || exit $?

        # debug
        # make PLATFORM=imx PLATFORM_FLAVOR=mx8mqevk \
        #  CFG_TEE_CORE_DEBUG=y CFG_TEE_CORE_LOG_LEVEL=3 \
        #  CFG_RPMB_FS=y CFG_RPMB_TESTKEY=y CFG_RPMB_WRITE_KEY=y CFG_REE_FS=n \
        #  CFG_TA_DEBUG=y CFG_TEE_CORE_TA_TRACE=1 CFG_TEE_TA_LOG_LEVEL=2 \
        #  CFG_IMXCRYPT=y CFG_CORE_HEAP_SIZE=131072

        ${CROSS_COMPILE64}objcopy -O binary ./out/arm-plat-imx/core/tee.elf ./out/arm-plat-imx/tee.bin || exit $?
        popd
        export CROSS_COMPILE=$AARCH64_TOOLCHAIN_PATH
        export ARCH=arm64
    fi

    if [ $build_tee_apps -eq 1 ]; then
        export TA_CROSS_COMPILE=$AARCH64_TOOLCHAIN_PATH
        export TA_DEV_KIT_DIR=../../../../imx-optee-os/out/arm-plat-imx/export-ta_arm64
        export TA_CPU=cortex-a53
        
        pushd MSRSec/TAs/optee_ta || exit $?
        if [ $clean -eq 1 ]; then
            rm -r ./out
        fi
        make CFG_ARM64_ta_arm64=y CFG_FTPM_USE_WOLF=y CFG_AUTHVARS_USE_WOLF=y || exit $?
        popd

        mkdir -p mu_platform_nxp/Microsoft/OpteeClientPkg/Bin/AuthvarsTa/Arm64/Test || exit $?
        mkdir -p mu_platform_nxp/Microsoft/OpteeClientPkg/Bin/fTpmTa/Arm64/Test || exit $?
        cp MSRSec/TAs/optee_ta/out/AuthVars/2d57c0f7-bddf-48ea-832f-d84a1a219301.ta  mu_platform_nxp/Microsoft/OpteeClientPkg/Bin/AuthvarsTa/Arm64/Test/ && \
        cp MSRSec/TAs/optee_ta/out/AuthVars/2d57c0f7-bddf-48ea-832f-d84a1a219301.elf mu_platform_nxp/Microsoft/OpteeClientPkg/Bin/AuthvarsTa/Arm64/Test/ && \
        cp MSRSec/TAs/optee_ta/out/fTPM/bc50d971-d4c9-42c4-82cb-343fb7f37896.ta mu_platform_nxp/Microsoft/OpteeClientPkg/Bin/fTpmTa/Arm64/Test/     && \
        cp MSRSec/TAs/optee_ta/out/fTPM/bc50d971-d4c9-42c4-82cb-343fb7f37896.elf mu_platform_nxp/Microsoft/OpteeClientPkg/Bin/fTpmTa/Arm64/Test/     || exit $?
        
        export -n TA_CROSS_COMPILE
        export -n TA_DEV_KIT_DIR
        export -n TA_CPU
    fi

    if [ $build_uboot_image -eq 1 ]; then
        pushd imx-mkimage/iMX8M || exit $?
        cp -f ../../firmware-imx/firmware/ddr/synopsys/lpddr4_pmu_train_*.bin . && \
        cp -f ../../firmware-imx/firmware/ddr/synopsys/ddr4_*.bin .             && \
        cp -f ../../firmware-imx/firmware/hdmi/cadence/signed_hdmi_imx8m.bin .  && \
        cp -f ../../imx-optee-os/out/arm-plat-imx/tee.bin .              && \
        cp -f ../../imx-atf/build/"$atf_plat"/release/bl31.bin .                    && \
        cp -f ../../uboot-imx/u-boot-nodtb.bin  .                    && \
        cp -f ../../uboot-imx/spl/u-boot-spl.bin .                   && \
        cp -f ../../uboot-imx/arch/arm/dts/"$uboot_dtb" .            && \
        cp -f ../../uboot-imx/tools/mkimage .                        && \
        mv mkimage mkimage_uboot                                                    || exit $?
        
        cd ..
        if [ $clean -eq 1 ]; then
            make SOC=$mkimage_SOC clean
        fi
        if [ $atf_plat == "imx8mn" ]; then
            make SOC=$mkimage_SOC flash_ddr4_evk 2>&1 | tee $MKIMAGE_WORK_DIR/spl_uboot.log || exit $?
        else
            make SOC=$mkimage_SOC flash_hdmi_spl_uboot 2>&1 | tee $MKIMAGE_WORK_DIR/spl_uboot.log || exit $?
        fi
        popd
        cp imx-mkimage/iMX8M/flash.bin ${TARGET_FIRMWARE_COMPONENTS_DIR}/flash.bin || exit $?
    fi

    if [ $build_uefi_tools -eq 1 ]; then
        pushd mu_platform_nxp && \
        cd MU_BASECORE        || exit $?
        if [ $clean -eq 1 ]; then
            cd BaseTools      && \
            make clean        || exit $?
            cd ..
        fi
        make -s -C BaseTools  || exit $?
        cd ..
        popd
    fi

    if [ $build_uefi -eq 1 ]; then
        pushd mu_platform_nxp || exit $?
        if [ $clean -eq 1 ]; then
            rm -rf Build
            rm -rf Conf
        else
            # Incremental build fix: rm -f Build/"${uefi_folder}"/${build_configuration}_GCC5/FV/Ffs/4E09D4EF-743F-4589-B5EF-8AC493F9DBE2ArmPlatformPrePiUniCore/4E09D4EF-743F-4589-B5EF-8AC493F9DBE2.efi
            rm -f Build/"${uefi_folder}"/${build_configuration}_GCC5/FV/Ffs/*ArmPlatformPrePiUniCore/*.efi
        fi
        export GCC5_AARCH64_PREFIX=$AARCH64_TOOLCHAIN_PATH
    
        python3 NXP/"${uefi_folder}"/PlatformBuild.py --setup || exit $?
        python3 NXP/"${uefi_folder}"/PlatformBuild.py --update || exit $?
        python3 NXP/"${uefi_folder}"/PlatformBuild.py -v TARGET=$build_configuration \
        PROFILE=${build_uefi_profile} MAX_CONCURRENT_THREAD_NUMBER=10 TOOL_CHAIN_TAG=GCC5 BUILDREPORTING=TRUE BUILDREPORT_TYPES="PCD" || exit $?

        pushd Build/"${uefi_folder}"/${build_configuration}_GCC5/FV || exit $?
        cp ../../../../../imx-windows-iot/build/firmware/its/uefi_imx8_unsigned.its .                   && \
        ../../../../../uboot-imx/tools/mkimage -f uefi_imx8_unsigned.its -r uefi.fit || exit $?
        popd
        popd
        cp mu_platform_nxp/Build/"${uefi_folder}"/${build_configuration}_GCC5/FV/uefi.fit ${TARGET_FIRMWARE_COMPONENTS_DIR}/uefi.fit || exit $?
    fi

    if [ $build_sign_images -eq 1 ]; then
        pushd imx-mkimage || exit $?
        rm -f print_fit_hab
        if [ $atf_plat == "imx8mn" ]; then
            make SOC=$mkimage_SOC print_fit_hab_ddr4 > $MKIMAGE_WORK_DIR/fit_hab.log || exit $?
        else
            make SOC=$mkimage_SOC print_fit_hab > $MKIMAGE_WORK_DIR/fit_hab.log || exit $?
        fi
        generate_spl_csf $MKIMAGE_WORK_DIR/spl_uboot.log $MKIMAGE_WORK_DIR/flash.bin || exit $?
        generate_fit_csf $MKIMAGE_WORK_DIR/spl_uboot.log $MKIMAGE_WORK_DIR/fit_hab.log $MKIMAGE_WORK_DIR/flash.bin || exit $?
        sign_uboot_binary $MKIMAGE_WORK_DIR/spl_uboot.log $MKIMAGE_WORK_DIR/flash.bin || exit $?
        popd

        pushd mu_platform_nxp/Build/"${uefi_folder}"/${build_configuration}_GCC5/FV || exit $?
        sign_uefi_binary uefi.fit || exit $?
        popd
        cp imx-mkimage/iMX8M/signed_flash.bin ${TARGET_FIRMWARE_COMPONENTS_DIR}/signed_flash.bin || exit $?
        cp mu_platform_nxp/Build/"${uefi_folder}"/${build_configuration}_GCC5/FV/signed_uefi.fit ${TARGET_FIRMWARE_COMPONENTS_DIR}/signed_uefi.fit || exit $?
    fi

    echo "-----------------------------------------------------------------"
    if [ $build_uboot_image -eq 1 ]; then
        echo "flash.bin copied to:" ${TARGET_FIRMWARE_COMPONENTS_DIR}/flash.bin || exit $?
    fi
    if [ $build_uefi -eq 1 ]; then
        echo "uefi.fit copied to:" ${TARGET_FIRMWARE_COMPONENTS_DIR}/uefi.fit || exit $?
    fi
    if [ $build_sign_images -eq 1 ]; then
        echo "signed_flash.bin copied to:" ${TARGET_FIRMWARE_COMPONENTS_DIR}/signed_flash.bin || exit $?
        echo "signed_uefi.fit copied to:" ${TARGET_FIRMWARE_COMPONENTS_DIR}/signed_uefi.fit || exit $?
    fi
    
    if [ $build_fw_monolith -eq 1 ]; then
        # Merge U-boot and UEFI for easier deployment.
        echo "firmware.bin created as:" ${TARGET_FIRMWARE_DIR}/firmware.bin || exit $?
        dd if=${TARGET_FIRMWARE_COMPONENTS_DIR}/flash.bin of=${TARGET_FIRMWARE_DIR}/firmware.bin bs=512 || exit $?
        dd if=${TARGET_FIRMWARE_COMPONENTS_DIR}/uefi.fit of=${TARGET_FIRMWARE_DIR}/firmware.bin bs=1024 seek=$uefi_offset_kb || exit $?
        
        if [ $build_sign_images -eq 1 ]; then
            echo "signed_firmware.bin created as:" ${TARGET_FIRMWARE_DIR}/signed_firmware.bin || exit $?
            dd if=${TARGET_FIRMWARE_COMPONENTS_DIR}/signed_flash.bin of=${TARGET_FIRMWARE_DIR}/signed_firmware.bin bs=512 || exit $?
            dd if=${TARGET_FIRMWARE_COMPONENTS_DIR}/signed_uefi.fit of=${TARGET_FIRMWARE_DIR}/signed_firmware.bin bs=1024 seek=$uefi_offset_kb || exit $?
        fi
    fi
    echo "Done"
}

# 7. main
# the main function of this script
#
#   7.1. echo selected configuration

echo building bootloader image for Windows 10 IOT core
echo "Build Configuration: " $build_configuration
echo -----------------
echo 
echo Selected configuration:
echo "clean              $clean"
echo "build_uboot        $build_uboot"
echo "build_atf          $build_atf"
echo "build_optee        $build_optee"
echo "build_tee_apps     $build_tee_apps"
echo "build_uboot_image  $build_uboot_image"
echo "build_uefi_tools   $build_uefi_tools"
echo "build_uefi         $build_uefi"
echo "build_sign_images  $build_sign_images"
echo "build_fw_monolith  $build_fw_monolith"
echo -----------------
if [ $build_all_selected -eq 0 ]; then
    echo 
    echo Warning \"-t all\" not set! Build of reduced feature set should be used for development purposes only and requires \"$script_name -t all\" to be run first.
fi
echo
echo Building..
echo

#  7.2. for each board
#       - set environment vars for board selected
#       - call build_board()
#
#  > Note: '$?' contains return value

# available configs bellow:
#   1) i.MX 8MQ EVK config
#   2) i.MX 8M Mini EVK config
#   3) i.MX 8M Nano EVK config

# i.MX 8MQ EVK config
if [ $build_8m -eq 1 ]; then
    echo "Board type IMX8M EVK" 
    bsp_folder="NXPEVK_iMX8M_4GB"
    uefi_folder="MCIMX8M_EVK_4GB"
    uboot_defconfig="imx8mq_evk_nt_defconfig"
    if [ $build_uboot_with_uuu_support -eq 1 ]; then
        uboot_defconfig="imx8mq_evk_nt_uuu_defconfig"
        if [ $build_uboot -eq 1 ]; then
            echo "$(tput setaf 1) Building uBoot image with uuu support! Defconfig: $uboot_defconfig $(tput sgr 0)"
        fi
    fi
    atf_plat="imx8mq"
    optee_plat="mx8mqevk"
    uboot_dtb="imx8mq-evk.dtb"
    mkimage_SOC="iMX8M"
    uefi_offset_kb=1500
    
    build_board
    # check return value
    if [ $? -gt 0 ]; then
        exit $?
    fi
fi

# i.MX 8M Mini EVK config
if [ $build_8m_mini -eq 1 ]; then
    echo "Board type IMX8MM EVK"
    bsp_folder="NXPEVK_iMX8M_Mini_2GB"
    uefi_folder="MCIMX8M_MINI_EVK_2GB"
    uboot_defconfig="imx8mm_evk_nt_defconfig"
    if [ $build_uboot_with_uuu_support -eq 1 ]; then
        uboot_defconfig="imx8mm_evk_nt_uuu_defconfig"
        if [ $build_uboot -eq 1 ]; then
            echo -e "$(tput setaf 1) Building uBoot image with uuu support! Defconfig: $uboot_defconfig $(tput sgr 0)"
        fi
    fi
    atf_plat="imx8mm"
    optee_plat="mx8mmevk"
    uboot_dtb="imx8mm-evk.dtb"
    mkimage_SOC="iMX8MM"
    uefi_offset_kb=1500
    
    build_board
    # check return value
    if [ $? -gt 0 ]; then
        exit $?
    fi
fi

# i.MX 8M Nano EVK config
if [ $build_8m_nano -eq 1 ]; then
echo "Board type IMX8MN EVK"
    bsp_folder="EVK_iMX8MN_2GB"
    uefi_folder=${bsp_folder}
    uboot_defconfig="imx8mn_ddr4_evk_nt_defconfig"
    if [ $build_uboot_with_uuu_support -eq 1 ]; then
        uboot_defconfig="imx8mn_ddr4_evk_nt_uuu_defconfig"
        if [ $build_uboot -eq 1 ]; then
            echo -e "$(tput setaf 1) Building uBoot image with uuu support! Defconfig: $uboot_defconfig $(tput sgr 0)"
        fi
    fi
    atf_plat="imx8mn"
    optee_plat="mx8mnevk"
    uboot_dtb="imx8mn-ddr4-evk.dtb"
    mkimage_SOC="iMX8MN"
    uefi_offset_kb=1500
    
    build_board
    # check return value
    echo Build has returned $? !
    if [ $? -gt 0 ]; then
        exit $?
    fi
fi

DESCRIPTION = "Linux kernel for the Xilinx Zynq"
SECTION = "kernel"
LICENSE = "GPLv2"

PROVIDES += "virtual/kernel"

KCONFIG_MODE="--alldefconfig"

KSRC ?= "git://github.com/openbmc/linux;protocol=git;branch=${KBRANCH}"
SRC_URI = "${KSRC}"

LINUX_VERSION_EXTENSION ?= "-${SRCREV}"

PV = "${LINUX_VERSION}+git${SRCPV}"

COMPATIBLE_MACHINE_${MACHINE} = "^${MACHINE}$"
KERNEL_CLASSES ?= "kernel-uimage"

inherit vivado-support

# patch in generated device tree
do_patch_append() {
    DT=`basename ${KERNEL_DEVICETREE} .dtb`
    if [ -r "${DEVICETREE_LOCATION}/${DT}.dts" ]; then
        cp ${DEVICETREE_LOCATION}/${DT}.dts \
            ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts
    fi
    if ! copy_over_device_tree_includes; then
        echo "Error: Expected device tree copy to succeed."
        echo "  Please provide a correct XILINX_GENERATED_DEVICE_TREE_PROJECT_LOCATION"
        echo "  in the configuration file (build/conf/local.conf)."
        exit 1
    fi
}

do_patch[nostamp] = "1"

inherit kernel
require recipes-kernel/linux/linux-yocto.inc

# From 4.16+ the COPYING file changed
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"
KERNEL_FEATURES_remove = "phosphor-gpio-keys"

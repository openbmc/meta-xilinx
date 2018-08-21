# Uses the xilinx-uboot repo maintained by enclustra for the Zynq
SECTION = "bootloaders"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=a2c678cfd4a4d97135585cad908541c6"

UBRANCH = "master"
PV .= "+${UBRANCH}+"
SRC_URI = "git://github.com/enclustra-bsp/xilinx-uboot.git;protocol=https"
SRCREV = "${AUTOREV}"
S = "${WORKDIR}/git"

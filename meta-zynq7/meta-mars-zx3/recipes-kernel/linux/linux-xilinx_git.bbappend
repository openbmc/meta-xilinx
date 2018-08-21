FILESEXTRAPATHS_prepend_zynq7 := "${THISDIR}/linux-xilinx/:"
SRC_URI_append_zynq7 = " file://defconfig"

DEVICETREE_LOCATION := "${THISDIR}/linux-xilinx"

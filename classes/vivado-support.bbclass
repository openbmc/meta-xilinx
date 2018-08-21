# Functions that provide support for using OpenBMC with vivado projects
# Copyright (C) 2018 ETH Zürich

XILINX_GENERATED_DEVICE_TREE_PROJECT_LOCATION ?= "${VIVADO_SDK_LOCATION}/device_tree_bsp_0"

export XILINX_GENERATED_DEVICE_TREE_PROJECT_LOCATION

copy_over_device_tree_includes() {
    device_tree_support=`find "$XILINX_GENERATED_DEVICE_TREE_PROJECT_LOCATION/" | grep "\.dtsi$"`
    cp -t "${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts" $device_tree_support
}

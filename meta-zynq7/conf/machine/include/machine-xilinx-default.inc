# Copyright (C) 2017 Xilinx 
# Released under the MIT license (see COPYING.MIT)

# Default Xilinx BSP Machine settings

MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

# File System Configuration
IMAGE_FSTYPES ?= "tar.gz cpio cpio.gz.u-boot"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-xilinx"

# U-Boot Configuration
PREFERRED_PROVIDER_virtual/bootloader ??= "u-boot-enclustra"
PREFERRED_PROVIDER_virtual/boot-bin ??= "${PREFERRED_PROVIDER_virtual/bootloader}"
PREFERRED_PROVIDER_u-boot ?= "u-boot-enclustra"
PREFERRED_PROVIDER_u-boot-fw-utils ?= "u-boot-fw-utils-enclustra"

UBOOT_BINARY ?= "u-boot.bin"
UBOOT_ELF ?= "u-boot"
UBOOT_ELF_aarch64 ?= "u-boot.elf"

MACHINEOVERRIDES .= ":zynq7"

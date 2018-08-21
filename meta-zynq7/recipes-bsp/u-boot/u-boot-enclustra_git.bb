require u-boot-common-enclustra_${PV}.inc
require recipes-bsp/u-boot/u-boot.inc

PROVIDES += "u-boot"
DEPENDS += "dtc-native"

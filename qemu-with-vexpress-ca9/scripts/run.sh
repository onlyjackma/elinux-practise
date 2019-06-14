#!/bin/bash

qemu-system-arm \
	-M vexpress-a9 \
	-m 512M \
	-kernel ../linux-4.9.11/arch/arm/boot/zImage \
	-dtb ../linux-4.9.11/arch/arm/boot/dts/vexpress-v2p-ca9.dtb \
	-nographic \
	-append "root=/dev/mmcblk0 console=ttyAMA0 rw init=/linuxrc" \
	-sd a9rootfs.ext3

qemu-system-arm -M vexpress-a9 \
     -kernel ../u-boot-2019.04/u-boot \
     -nographic \
     -m 512M \
     -sd a9rootfs.ext3
 	 -append "root=/dev/mmcblk0 rw console=ttyAMA0"
     #-net nic -net tap ,ifname=tap0 \

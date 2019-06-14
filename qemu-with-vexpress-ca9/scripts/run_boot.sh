qemu-system-arm -M vexpress-a9 \
     -kernel ../u-boot-2019.04/u-boot \
     -nographic \
     -m 512M \
     -sd a9rootfs.ext3 \
     -net nic -net tap,ifname=tap0,script=no,downscript=no

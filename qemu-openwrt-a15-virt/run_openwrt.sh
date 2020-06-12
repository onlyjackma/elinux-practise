qemu-system-arm -nographic -M virt -m 64 -kernel ../../openwrt/bin/targets/armvirt/32/openwrt-armvirt-32-zImage \
	 -net nic,macaddr=52:54:00:55:66:FE -net tap,ifname=tap1,script=no,downscript=no \
	  -drive file=../../openwrt/bin/targets/armvirt/32/openwrt-armvirt-32-rootfs-ext4.img,format=raw,if=virtio -append 'root=/dev/vda rootwait'

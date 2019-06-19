qemu-system-arm -nographic -M virt -m 64 -kernel openwrt-armvirt-32-zImage \
	 -net nic,macaddr=52:54:00:55:66:FE -net tap,ifname=tap1,script=no,downscript=no \
	  -drive file=openwrt-armvirt-32-root.ext4,format=raw,if=virtio -append 'root=/dev/vda rootwait'

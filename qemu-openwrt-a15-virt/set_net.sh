sudo ip tuntap add tap0 mode tap
sudo ip tuntap add tap1 mode tap
sudo ip link add br0 type bridge
sudo brctl addif br0 tap0
sudo brctl addif br0 tap1
sudo ifconfig tap0 0.0.0.0
sudo ifconfig tap1 0.0.0.0
sudo ifconfig br0 192.168.20.1
sudo iptables -A POSTROUTING -t nat -o enx000ec6cc38ea -j MASQUERADE


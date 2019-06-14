#!/bin/sh 

ip link add br0 type bridge
ip tuntap add dev tap0 mode tap
ip link set dev tap0 master br0   # set br0 as the target bridge for tap0
#ip link set dev enx000ec6cb78b4 master br0   # set br0 as the target bridge for eth0
ip link set dev br0 up

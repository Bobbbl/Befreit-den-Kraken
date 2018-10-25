#!/bin/bash

echo "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
ap_scan=1
update_config=1
" > /etc/wpa_supplicant/wpa_supplicant.conf

echo "network={
	ssid=\"$1\"
	psk=\"$2\"
}" >> /etc/wpa_supplicant/wpa_supplicant.conf


sudo systemctl daemon-reload
sudo systemctl restart dhcpcd

#!/bin/bash

rm /var/run/wpa_supplicant/wlan0
sleep 1
sudo wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf -D wext

sleep 5

sudo reboot
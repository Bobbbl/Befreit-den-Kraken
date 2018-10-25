#!/bin/bash
echo "Installiere Komponenten"
apt-get update
apt-get upgrade
apt-get install wpasupplicant

echo "Installiere QT"
apt-get install qt4-default
apt-get install qt-dev-tools
apt-get install qtcreator
apt-get install gcc
apt-get install xterm
apt-get install git-core
apt-get install subversion

echo "Installiere SAMBA Support"
apt-get install samba

echo "Installiere Touch"
echo "max_usb_current=1
hdmi_group=2
hdmi_mode=87
hdmi_cvt 800 480 60 6 0 0 0
hdmi_drive=1" >> /boot/config.txt

chmod +x Einrichten.sh
chmod +x NewCredentials.sh

echo "Aktiviere und Installieren des 1-Wire Bus"
echo "dtoverlay=w1-gpio,gpiopin=4,pullup=on" >> /boot/config.txt
echo "Trage Module fest in System ein. Verfuegbar bei REBOOT"
echo "w1-gpio pullup=1
w1-therm" >> /etc/modules

sudo reboot
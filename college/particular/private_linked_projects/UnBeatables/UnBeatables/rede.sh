killall wpa_supplicant
wpa_supplicant -B -iwlan0 -c/etc/wpa_supplicant.conf -Dnl80211
dhclient wlan0
ifconfig wlan0 10.0.25.1 up
ifconfig wlan0 10.0.31.2 netmask 255.255.0.0


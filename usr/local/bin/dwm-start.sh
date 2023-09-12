#!/bin/sh

#black bg
xsetroot -solid black

#path to background
/home/brian/.config/conky/lux-hud/startall.sh &


## status bar
dwmblocks &

#traying
sleep 1
#/usr/bin/ck-launch-session &
#exec /usr/bin trayer --edge top --align center --distance 1 --SetDockType true --SetPartialStrut true --expand true --widthtype percent --width 2 --height 32 &
#/usr/local/bin/stalonetray &
nm-applet &
pasystray &
#bluez &
#solaar &

# Compositor
#compton &
picom &

# Wallpaper
nitrogen --restore &

# Display Setting
#Arch
#RX 560
xrandr --output HDMI-A-0 --auto --output DVI-D-0 --auto --left-of HDMI-A-0 --output DisplayPort-0 --auto --right-of HDMI-A-0 &
#RX 570
#xrandr --output HDMI-1 --auto --output DVI-D-1 --auto --left-of HDMI-1 --output DP-1 --auto --right-of HDMI-1 &
#Gentoo
#xrandr --output HDMI-A-0 --auto --output DVI-D-0 --auto --left-of HDMI-A-0 --output DisplayPort-0 --auto --right-of HDMI-A-0

#start dwm after loop
exec /usr/local/bin/dwm > /dev/null

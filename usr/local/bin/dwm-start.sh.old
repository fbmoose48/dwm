#!/bin/sh

# --- commands here and before the "while true; do" are run once
#xrdb -merge ~/.Xresources

#black bg
xsetroot -solid black

#path to background
#/usr/share/backgrounds/abstract/Flow.png
/home/brian/.config/conky/lux-hud/startall.sh &


## while loops to update statusbar
#15 min while loop
while true; do
#updates
	#Arch
	checkupdates | wc -l > /tmp/CurUPD.tmp
	#Gentoo
	#emerge -pvDuN world|awk '/ebuild/ {if ($2=="U") {u++}; if ($2=="R") {r++}; if ($2=="D") {d++}; if($2=="F"){f++}; if($2=="I"){i++}; if($2=="B"){b++};} END {total=u+r+d+f+i+b; if(total>0){ printf total};}' > /tmp/CurUPD.tmp
#weather
	weather.sh 06471 > /tmp/CurFCST.tmp
	sleep 900s
done &
#1 min while loop
while true; do
#ssid
	#nmcli dev wifi | grep -E '^[*]' | awk '/*/ {print $3}' > /tmp/CurSSID.tmp
#network signal
	#nmcli dev wifi | grep -E '^[*]' | awk '/*/ {print $9}' > /tmp/CurNET.tmp
#public ip
	curl ipinfo.io/ip 1 > /tmp/CurIP.tmp
	sleep 60s
done &
#30s while loop
while true; do
#battery capacity
	#cat /sys/class/power_supply/BAT0/capacity > /tmp/BATCAP.tmp
	sleep 30s
done &
#15s while loop
while true; do
#battery status
	#cat /sys/class/power_supply/BAT0/status > /tmp/BATSTAT.tmp
	sleep 15s
done &
#5s while loop
while true; do
#time
	CLK=$( date +'%a %b %d %R' )
#volume
	#VOL=$( amixer get Master | tail -1 | awk '{ print $5 }' | tr -d '[]' )
#ssid
	#SSID=$(< /tmp/CurSSID.tmp)
#network signal
	#NET=$(< /tmp/CurNET.tmp)
#public ip
	IP=$(< /tmp/CurIP.tmp)
#battery
	#BATSTAT=$(< /tmp/BATSTAT.tmp)
	#BATCAP=$(< /tmp/BATCAP.tmp)
#updates
	UPD=$(< /tmp/CurUPD.tmp)
#weather
	FCST=$(< /tmp/CurFCST.tmp)

#this one is not so good, increases a delay of 1-2s of the updating.
#put it in the xsetrootname plz (tip of the day, do not put | as first char after "
	#xsetroot -name "$FCST |  $UPD | $IP | $BATSTAT $BATCAP % | $CLK"
	xsetroot -name "$FCST |  $UPD | $IP | $CLK"
	sleep 5s
done &
#status bar loop is done

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

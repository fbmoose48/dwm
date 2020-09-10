#!/bin/sh

# --- commands here and before the "while true; do" are run once
#xrdb -merge ~/.Xresources
#open screensaver (so that gnome-screensaver-command -l works)
#/usr/bin/gnome-screensaver &
#open pwer manager
#exec gnome-power-manager
#black bg
xsetroot -solid black
#path to background
#/usr/share/backgrounds/abstract/Flow.png
/home/brian/.config/conky/lux-hud/startall.sh &


## while loops to update statusbar
#15 min while loop
while true; do
#updates
	checkupdates | wc -l > /tmp/CurUPD.tmp
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
#15s while loop
while true; do
#total memory
	#free -h | awk '/^Mem:/ {print $2}' > /tmp/CurMEMTGI.tmp
	#MEMT=( $MEMTGI/1024 );
#free memory
	#free -h | awk '/^Mem:/ {print $3}' > /tmp/CurMEMFGI.tmp
	#MEMF=( $MEMFGI/1024 );
#battery
	#battotal=`awk '/last full capacity/{print $4}' < /proc/acpi/battery/BAT0/info`;
	#batfree=`awk '/remaining capacity/{print $3}' < /proc/acpi/battery/BAT0/state`;
	#battper=$(( 100*$batfree/$battotal ));
	#battery=`awk '/charging state/{print $3}' < /proc/acpi/battery/BAT0/state`;
#memfreak to get free memory in MB
	#memfreak2=`grep MemFree /proc/meminfo | awk '{ print $2 }'`;
	#memfreak=$(( $memfreak2/1024 ));
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
#updates
	UPD=$(< /tmp/CurUPD.tmp)
#weather
	FCST=$(< /tmp/CurFCST.tmp)
#memory
	#MEMTGI=$(< /tmp/CurMEMTGI.tmp)
	#MEMFGI=$(< /tmp/CurMEMFGI.tmp)
#loadavg
	#AVG=$( cat /proc/loadavg | cut -d ' ' -f -3 )
#network stats in Bytes
	#NW=$( dstat -n --nocolor 1 1 | tail -1 | awk '{ print $1, $2}' )
#this one is not so good, increases a delay of 1-2s of the updating.
#put it in the xsetrootname plz (tip of the day, do not put | as first char after "
	#xsetroot -name "$AVG | $memfreak MB | $MEMFGI / $MEMTGI | $SSID $NET | $battper% $battery | Vol: $VOL | $CLK | "
	xsetroot -name "$FCST |  $UPD | $IP | $CLK"
	sleep 5s
done &
#status bar loop is done

#traying
sleep 1
#/usr/bin/ck-launch-session &
#exec /usr/bin trayer --edge top --align center --distance 1 --SetDockType true --SetPartialStrut true --expand true --widthtype percent --width 2 --height 32 &
#/usr/local/bin/stalonetray &
#dwmblock &
nm-applet &
blueman-applet &
#pa-applet &
pasystray &
#/usr/bin/gnome-volume-control-applet &

# Compositor
#compton &
picom &

# Wallpaper
#feh -z -Z --bg-scale /home/brian/Pictures/dwm_pattern.png
#feh -z -Z -B black -b trans --bg-scale /home/brian/Pictures/Flow.png
nitrogen --restore &

# Display Setting
#Arch 3-monitor
xrandr --output HDMI-1 --auto --output DVI-D-1 --auto --left-of HDMI-1 --output DP-1 --auto --right-of HDMI-1 &
#Gentoo 3-monitor
#xrandr --output HDMI-A-0 --auto --output DVI-D-0 --auto --left-of HDMI-A-0 --output DisplayPort-0 --auto --right-of HDMI-A-0

#start freshly compiled dwm after loop
exec /usr/local/bin/dwm > /dev/null
#start stable dwm after loop
#exec /usr/local/bin/dwm-6.2-20200807 > /dev/null

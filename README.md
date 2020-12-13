# Custom build of dwm - dynamic window manager

dwm is an efficient dynamic window manager for X.

## patches



## Installation

```
sudo rm -r dwm
git clone https://github.com/fbmooose48/dwm.git
cd dwm
sudo make install
sudo mv usr/share/xsessions/dwm.desktop /usr/share/xsessions
sudo mv usr/local/bin/dwm-start.sh /usr/local/bin
sudo chmod +x /usr/local/bin/dwm-start.sh
emerge --ask x11-libs/libXinerama x11-libs/libXft media-fonts/hack x11-misc/stalonetray x11-misc/picom x11-apps/xrandr x11-apps/xsetroot x11-misc/nitrogen gnome-extra/nm-applet
```
### Gentoo
```
nerd-fonts-source-code-pro 
https://github.com/ryanoasis/nerd-fonts
```

## Requirements

In order to build dwm you need the Xlib header files.
`make` is required to build.

+ libxft
+ ttf-hack
+ st
+ dmenu

Also, you will need to add the following :

+ nerd-fonts-source-code-pro

### dwm-start.sh requires
+ stalonetray
+ picom
+ xrandr
+ xsetroot
+ nitrogen
+ nm-applet

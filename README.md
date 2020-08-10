# Custom build of dwm - dynamic window manager

dwmu is an efficient dynamic window manager for X.

## patches



## Installation

```
git clone https://github.com/fbmooose48/dwm
cd dwm
sudo make install
sudo mv usr/share/xsessions/dwm.desktop /usr/share/xsessions
sudo mv usr/local/bin/dwm-start.sh /usr/local/bin
sudo chmod +x /usr/local/bin/dwm-start.sh
sudo pacman -S --needed libxft ttf-hack ttf-joypixels stalonetray picom xorg-xrandr xorg-xsetroot nitrogen nm-applet 
yay -S --needed nerd-fonts-source-code-pro libxft-bgra
```
## Requirements

In order to build dmenu you need the Xlib header files.
`make` is required to build.

+ libxft
+ ttf-hack
+ ttf-joypixels
+ st
+ dmenu

Also, you will need to add the following from the AUR:

+ nerd-fonts-source-code-pro
+ libxft-bgra https://aur.archlinux.org/packages/libxft-bgra/ (needed for colored fonts and emojis)

### dwm-start.sh requires
+ stalonetray
+ picom
+ xorg-xrandr
+ xorg-xsetroot
+ nitrogen
+ nm-applet


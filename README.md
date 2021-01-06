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
sudo echo "exec /usr/local/bin/dwm-start.sh" >> ~/.xinitrc
sudo pacman -S --needed libxft ttf-hack ttf-joypixels picom xorg-xrandr xorg-xsetroot nitrogen stalonetray network-manager-applet pasystray blueman
yay -S --needed nerd-fonts-source-code-pro libxft-bgra
```
### Gentoo
```
emerge --ask x11-libs/libXinerama x11-libs/libXft media-fonts/hack x11-misc/stalonetray x11-misc/picom x11-apps/xrandr x11-apps/xsetroot x11-misc/nitrogen gnome-extra/nm-applet
```
### Ubuntu
```
sudo apt install libxinerama-dev libfontconfig1-dev libharfbuzz-dev xorg-dev fonts-hack fonts-powerline compton lxrandr x11-xserver-utils nitrogen stalonetray pasystray network-manager-gnome
```
### Sauce Code Font
```
git clone https://github.com/ryanoasis/nerd-fonts.git
cd nerd-fonts
./install.sh SourceCodePro
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




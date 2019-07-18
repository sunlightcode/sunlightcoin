
Debian
====================
This directory contains files used to package sunlightcoind/sunlightcoin-qt
for Debian-based Linux systems. If you compile sunlightcoind/sunlightcoin-qt yourself, there are some useful files here.

## sunlightcoin: URI support ##


sunlightcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install sunlightcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your sunlightcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/sunlightcoin128.png` to `/usr/share/pixmaps`

sunlightcoin-qt.protocol (KDE)


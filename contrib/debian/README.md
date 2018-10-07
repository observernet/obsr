
Debian
====================
This directory contains files used to package obsrd/obsr-qt
for Debian-based Linux systems. If you compile obsrd/obsr-qt yourself, there are some useful files here.

## obsr: URI support ##


obsr-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install obsr-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your obsrqt binary to `/usr/bin`
and the `../../share/pixmaps/obsr128.png` to `/usr/share/pixmaps`

obsr-qt.protocol (KDE)


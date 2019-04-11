[![Snap Status](https://build.snapcraft.io/badge/observernet/obsr.svg)](https://build.snapcraft.io/user/observernet/obsr) 
- [OBSR SNAP FAQ](#obsr-snap-faq)
  - [How to install snapd?](#how-to-install-snapd)
  - [How to install?](#how-to-install)
    - [To install the latest stable version:](#to-install-the-latest-stable-version)
    - [Install latest candidate version:](#install-latest-candidate-version)
    - [Install latest beta version (launchpad snap builds):](#install-latest-beta-version-launchpad-snap-builds)
    - [Install latest edge version (snapcraft snap):](#install-latest-edge-version-snapcraft-snap)
  - [How to update/upgrade?](#how-to-updateupgrade)
  - [How to UnInstall?](#how-to-uninstall)
  - [Where is OBSR snap's default datafolder?](#where-is-obsr-snaps-default-datafolder)
  - [How do I launch QT/Daemon/CLI/tx?](#how-do-i-launch-qtdaemonclitx)
    - [Launch QT from startmenu](#launch-qt-from-startmenu)
    - [Launch daemon/qt/cli/tx from terminal](#launch-daemonqtclitx-from-terminal)

<html><iframe src="https://snapcraft.io/obsr/embedded?button=black&channels=true&summary=true&screenshot=true" frameborder="0" width="100%" height="840px" style="border: 1px solid #CCC; border-radius: 2px;"></iframe></html>

# OBSR SNAP FAQ

Most questions which came up and here we are most frequent questions.

## How to install snapd?

Snap is pre-installed and ready to go on the following:

- [Ubuntu 16.04.4 LTS (Xenial Xerus)](https://www.ubuntu.com/) or later, including [Ubuntu 18.04 LTS (Bionic Beaver)](https://www.ubuntu.com/desktop/features) and [Ubuntu 18.10 (Cosmic Cuttlefish)](https://wiki.ubuntu.com/CosmicCuttlefish/ReleaseNotes).
- Most [recognised Ubuntu flavours](https://wiki.ubuntu.com/DerivativeTeam/Derivatives) built on one of the above Ubuntu releases. An exception is [Lubuntu](https://docs.snapcraft.io/t/installing-snap-on-lubuntu/9965).
- [Solus 3](https://getsol.us/home/) and above.
- [Zorin OS](https://zorinos.com/).

For more info about other distributions please check [installing snapd](https://docs.snapcraft.io/installing-snapd/6735) on [snapcrafts documentation page](https://docs.snapcraft.io/).

## How to install?

If you run it productive, then please use ***always latest stable version***.

There are 4 different channels:
- stable
- candidate
- beta
- edge

### To install the latest stable version:
  _(this is always current latest release version, built from release tag)_

  `sudo snap install --stable obsr`

### Install latest candidate version:
  _(this is always current latest release candidate (RC) version, built from release tag or commit)_

  `sudo snap install --candidate obsr`

### Install latest beta version (launchpad snap builds):
  _(this is launchpad version, built from master and auto built 4 times a day if there are any changes)_
  _(snaps built on launchpad are automaticly released under beta channel)_
  `sudo snap install --beta obsr`

### Install latest edge version (snapcraft snap):
  _(this is always current latest version built from latest commit on master)
  _(edge builds with snapcraft on each commit to master)_

  `sudo snap install --edge obsr`

## How to update/upgrade?

Run `sudo snap refresh` to refresh all snaps of your system.

You can specify branch from which you want to refresh, example with --edge: `sudo snap refresh --edge obsr` 

for more info about usage of snap, run `snap --help`.

## How to UnInstall?

- ##### !!!WARNING!!! backup data folder before uninstalling snap
  if you uninstall, your datafolder `~/snap/obsr/common/.obsr` will be deleted.

  **Please make always a backup of your folder `~/snap/obsr/common/.obsr`** ***before you uninstall obsr snap***.

  to uninstall, run: `sudo snap remove obsr`.

## Where is OBSR snap's default datafolder?

Default data folder for snap builds is located at `~/snap/obsr/common/.obsr`.

If you have never launched snap before, this folder will be created on first start.

## How do I launch QT/Daemon/CLI/tx?

### Launch QT from startmenu

In ubuntu, debian and other linux systems, if you have installed any desktop, then you should find 3 launchers/icons in your start menu:

- OBSR Qt
- OBSR Qt (Testnet)
- OBSR Qt (Regtest)

### Launch daemon/qt/cli/tx from terminal

We used a dot (`.`) insted of a hyphen (`-`) to run obsr snap build:

- for main network (_you can use `obsr.daemon` --testnet too, but we added `obsr.daemon-testnet` for that, check bellow._)
  - `obsr.daemon`
  - `obsr.cli`
  - `obsr.qt`
- for testnet
  - `obsr.daemon-testnet`
  - `obsr.cli-testnet`
  - `obsr.qt-testnet`
- for regtest
  - `obsr.daemon-regtest`
  - `obsr.cli-regtest`
  - `obsr.qt-regtest`

If you want to use obsr-tx, then it would be `obsr.tx`.

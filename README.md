# classikstyles
## Overview
Fork of KDE Breeze to provide Classik and Kite window decoration styles in a binary.
* Also provides Oxygen/Breeze and Redmond button icon styles;
* Provides both a Window Decoration and an Application Style so that icons in dockable panels match the titlebar icons;
* Configurable button spacing (left and right);
* Configurable whether to draw bold button icons for HiDPI displays.

## Installation
### Pre-built packages
OpenSUSE Tumbleweed/Leap repository:
> https://software.opensuse.org//download.html?project=home%3Apaul4us&package=classikstyles

> NB: for Leap you will first need to install newer KDE packages from https://en.opensuse.org/SDB:KDE_repositories

&nbsp;
&nbsp;

Raw RPM binary package from OpenSUSE Tumbleweed - these RPM packages may also work in other distributions:

> https://download.opensuse.org/repositories/home:/paul4us/openSUSE_Tumbleweed/x86_64/classikstyles-1.0.breeze5.21.80-25.1.x86_64.rpm (x64)

> https://download.opensuse.org/repositories/home:/paul4us/openSUSE_Tumbleweed/i586/classikstyles-1.0.breeze5.21.80-25.1.i586.rpm (x86)

> https://download.opensuse.org/repositories/home:/paul4us/openSUSE_Factory_ARM/aarch64/classikstyles-1.0.breeze5.21.80-25.1.aarch64.rpm (ARM64)

> https://download.opensuse.org/repositories/home:/paul4us/openSUSE_Factory_ARM/armv7hl/classikstyles-1.0.breeze5.21.80-20.1.armv7hl.rpm (ARM32)

&nbsp;
&nbsp;

### Compile from source
#### OpenSUSE Tumbleweed/Leap build dependencies
(Leap requires newer KDE packages from https://en.opensuse.org/SDB:KDE_repositories first):
```
sudo zypper in cmake extra-cmake-modules libQt5Core-devel libQt5Gui-devel libQt5DBus-devel libqt5-qtx11extras-devel libkdecoration2-devel kcoreaddons-devel kguiaddons-devel kconfigwidgets-devel kwindowsystem-devel ki18n-devel kiconthemes-devel kpackage-devel libQt5QuickControls2-devel frameworkintegration-devel kcmutils-devel
```

#### Ubuntu/KDE Neon build dependencies
For Ubuntu-based distributions you will first need to edit the install.sh file and set the DKDE_INSTALL_LIBDIR as follows:
```
-DKDE_INSTALL_LIBDIR=lib
```
then install the following dependencies:
```
sudo apt install build-essential libkf5config-dev libkdecorations2-dev libqt5x11extras5-dev qtdeclarative5-dev extra-cmake-modules libkf5guiaddons-dev libkf5configwidgets-dev libkf5windowsystem-dev libkf5coreaddons-dev gettext cmake libkf5iconthemes-dev libkf5package-dev
```

Build and install from source script:
```
chmod +x install.sh
./install.sh
```

Uninstall build script:
```
chmod +x uninstall.sh
./uninstall.sh
```

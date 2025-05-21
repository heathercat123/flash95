# Adobe Flash 9-10 for Windows 9x

<p align="center">
  <img src="https://raw.githubusercontent.com/heathercat123/flash95/master/img/screenshot.png" />
</p>

## Introduction

This project is a work-in-progress backport of Adobe Flash 9-10 to Windows 95 based on MattKC's .NET backport. Currently, version 9 is believed to be mostly functional while work on 10 has just begun.

Officially, Adobe Flash 9 never supported anything below 98, and Flash 10 never supported anything below 2000. This project changes that, backporting Adobe Flash Player 9 to 95/NT 3.5 and Flash Player 10 to 9x.


## Installation

### Windows 95

Adobe Flash 9 optionally requires the following to be installed:

- **Internet Explorer 5.01.** The installer is packaged in this repository at `bin/msie501`. An stub is used if it isn't installed
- **Windows Socket 2 Update.** The installer is package in this repository at `bin/winsock2`. An incomplete wrapper is used if it isn't installed.

Once those are installed, simply download the ZIP from the Releases tab, unzip and execute! After that, applications and games written for Adobe Flash 9 should run.

## Known Issues

In my testing, Adobe Flash 9 appears to largely work now, but `flash.net.SharedObject` doesn't work and Flash may still make some calls to missing system functions that need to be patched or reimplemented. However, Adobe Flash 10 has more issues, such as broken drag and drop or the inability to run any SWFs made specifically for it. If you run into an unexpected exception, a page fault or an error message, feel free to make a thread in the *Issues* tab.

## Credits
- [MattKC](https://github.com/itsmattkc) for dotnet9x.
- [DaniElectra](https://github.com/DaniElectra) for [winsock351](https://github.com/DaniElectra), which in our case allows Adobe Flash to run on down to Windows NT 3.5.
- Big Monstro for [the backport of Adobe Flash 7 to Windows NT 3.51](http://www.win3x.org/win3board/viewtopic.php?t=15907).

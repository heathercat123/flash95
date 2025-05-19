@echo off

::
:: Arguments:
::    novcvars: Do not run VCVARS32 from MSVC420
::    flashbin: Do not patch Adobe Flash and use it pre-patched
::    noflash: Do not patch Adobe Flash and don't use it pre-patched
:: You need to run as administrator if patching Adobe Flash
::
:: If anyone knows how to PROPERLY check for arguments, please open a pull request!
::

echo Setting variables...

:: Path to the modded dotnet9x (flash95)
set dotnetpath=%~dp0

:: Build folder
set rootbuild=%dotnetpath%\build

:: Patches folder
set patchespath=%dotnetpath%\patches

:: Path to my modded version of @DaniElectra's winsock351
set winsockpath=%dotnetpath%\winsock351

:: Set to whatever version of adobe flash you want to use if a patch is available in \patches\
rem set flashversion=9r277
set flashversion=10r12_36

:: Name of the Flash EXE
set flash=flashplayer%flashversion%_win_sa_debug.exe

:: Path where Flash EXEs are stored
:: For unpatched: Use the original file Name
:: For pre-patched: Original file name.exe + '-patch'
set flashpath=%dotnetpath%\flashbin

:: Path where MSVC is stored
:: Add '\vc98' if using MSVC600
:: Get it from here https://github.com/itsmattkc/msvc600
set msvcpath=%dotnetpath%\msvc600\vc98
rem set msvcpath=..\msvc420

:: Path for the generated README file
:: Using and underscore to make it show up as first in explorer
set readme=%rootbuild%\_README.txt

if "%1" == "novcvars" goto build
:: god please forgive me
if "%2" == "novcvars" goto build
if "%3" == "novcvars" goto build
echo Running VCVARS...
call %msvcpath%\bin\VCVARS32.BAT x86

:build
echo Creating build folder...
if exist %rootbuild% rd /s /q %rootbuild%
md %rootbuild%

echo Preparing to build the wrappers...
cd %dotnetpath%\wrappers\
if exist .\build rd /s /q .\build
md build
cd build
cmake %dotnetpath%\wrappers\ -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug
echo Building the wrappers...
nmake
echo Moving the wrappers to the build folder...
move corkel32.dll %rootbuild%
move corusr.dll %rootbuild%
move crypt32.dll %rootbuild%
move corshel.dll %rootbuild%
move cornt.dll %rootbuild%
REM move iphlpapi.dll %rootbuild%
:: move ws2_32.dll %rootbuild%
:: We don't need \wrappers\build\ anymore
cd %rootbuild%
rd /s /q %dotnetpath%\wrappers\build\

:: Winsock 2 -> 1.1 wrapper
:: TODO: Properly integrate it into this repo (LGPL code can be used in GPL)
cd %winsockpath%
nmake
move %winsockpath%\Debug\ws2_32.dll %rootbuild%

:: Internet Extensions for Win32
copy %dotnetpath%\bin\wininet\wininet.dll %rootbuild%

:: Microsoft C Runtime Library
copy %dotnetpath%\bin\msvcrt\msvcrt.dll %rootbuild%

:: README
echo Writing README...

echo If you have Winsock 2 installed or you are on Windows NT 4, please delete ws2_32.dll! > %readme%
echo If you have the 32-bit version of Internet Explorer 3 (included in Windows 95 OSR2) or newer installed, delete wininet.dll and urlmon.dll >> %readme%
echo If you have the 32-bit version of Internet Explorer 5 (included Windows 98 SE and 2000) or newer installed, delete crypt32.dll >> %readme%
echo. >> %readme%
echo Have fun! >> %readme%
echo    - Heathercat123 >> %readme%

:: Adobe Flash
if "%1" == "noflash" goto end
:: god please forgive me
if "%2" == "noflash" goto end
if "%3" == "noflash" goto end
if "%1" == "flashbin" goto flashbin
:: god please forgive me
if "%2" == "flashbin" goto flashbin
if "%3" == "flashbin" goto flashbin
echo Patching Adobe Flash %flashversion%...
:: For relative flashpath
cd %dotnetpath%
:: BSPATCH limitation workaround
copy %flashpath%\%flash% %patchespath%\%flash%
cd %patchespath%
bspatch.exe %flash% %flash%-new flash%flashversion%.bdf
del %patchespath%\%flash%
:: For relative flashpath
cd %dotnetpath%
move %patchespath%\%flash%-new %rootbuild%\%flash%
goto end

:flashbin
:: For relative flashpath
cd %dotnetpath%
copy %flashpath%\%flash%-patch %rootbuild%\%flash%

:end
cd %dotnetpath%
pause

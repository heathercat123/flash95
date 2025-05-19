# DLL Wrappers

These are DLL wrappers for system DLLs that Adobe Flash gets redirected to. They implement most of the functions that Flash requires, pass-through the ones that already exist, and implement or stub the ones that don't. Many of the stubs never get called at all, they only got linked with Flash due to the usage of a newer C++ runtime.

For compatibility with Windows 95, it is highly recommended that these be compiled with Microsoft Visual C++ 4.20 (MSVC420). For your convenience, since MSVC420's installer doesn't work well on newer versions of Windows, MattKC created a ["portable" version](https://github.com/itsmattkc/MSVC420) that you can simply clone and use.

# Binary/unmanaged DLL patches

These are `bdiff` patches that you have to apply to Adobe Flash when building this repository.

The patches redirects imports from system DLLs (e.g. `KERNEL32.DLL`) to our wrappers (e.g. `CORKEL32.DLL`) and also disables MMX since those instructions do not work on Windows 95 (even if the CPU supports them).

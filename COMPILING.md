 # Compiling
 
 ## Using the batch file
 1. Install [CMake](https://cmake.org/)
 1. Create a new folder called `flashbin`
 1. Get Adobe Flash 9r277 from [here](https://archive.org/download/flashplayerarchive/get/flashplayer/installers/archive/fp9_debug_archive.zip) and put in in flashbin
 1. Run this command at the root of this repository: `git clone https://github.com/itsmattkc/MSVC600.git`
 1. Run `build.bat` as an administrator
 The build folder should now contain compiled files.
 
 ## Compiling manually
 1. Install [CMake](https://cmake.org/)
 2. Get Microsoft Visual C++ 6 from [here](https://github.com/itsmattkc/MSVC600)
 3. Open a command prompt (`cmd`)
 4. Run `VC98/BIN/VCVARS31.BAT x86` from Visual C++ 6
 5. Create a new folder in `wrappers` where your compiled object will go, such as a `build` folder
 6. `cd` to this new folder in your command prompt
 7. Configure your project using CMake:
  `cmake ..\ -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release`
  - You may replace `..\` by the path to the `wrappers` folder
  - You may replace `Release` by `Debug` to build debug builds
8. Build the wrappers by running `NMake`
9. There should now be a compiled `CORKEL32.DLL` and `CORUSR.DLL` in the build folder. Move those to any other folder on your computer.
10. Download Adobe Flash 9r277 from [here](https://archive.org/download/flashplayerarchive/get/flashplayer/installers/archive/fp9_debug_archive.zip) and put it in `patches`
11. Open a command prompt as administrator
12. Run this command:
  `bspatch.exe flashplayer9r277_win_sa_debug.exe flashplayer9r277_win_sa_debug-patched.exe flash9r277.bdf`
13. Move the resulting file into the same folder as you put the wrapper in
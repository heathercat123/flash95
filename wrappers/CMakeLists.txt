cmake_minimum_required(VERSION 3.13)

project(corkel32 C)

set(CMAKE_BUILD_TYPE Release)

add_library(corkdebug OBJECT
  debug.c
)
link_libraries(corkdebug)

# KERNEL32 => CORKEL32
add_library(corkel32 SHARED
  kernel32.c
  advapi32.c
  comdlg32.c
  corkel32.def
)

# NTDLL => CORNT
add_library(cornt SHARED
  ntdll.c
  mscms.c
  cornt.def
)

# USER32 => CORUSR
add_library(corusr SHARED
  user32.c
  urlmon.c
  corusr.def
)

# CRYPT32 => CRYPT32
add_library(crypt32 SHARED
  crypt32.c
  crypt32.def
)

# SHELL32 => CORSHEL
add_library(corshel SHARED
  shell32.c
  corshel.def
)

## For VPC 5.1
## IPHLPAPI => IPHLPAPI
#add_library(iphlpapi SHARED
#  iphlpapi.c
#  iphlpapi.def
#)

## Currently unused
## ws2_32 => ws2_32
#add_library(ws2_32 SHARED
#  ws2_32.c
#  ws2_32.def
#)
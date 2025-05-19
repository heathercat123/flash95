#define _WIN32_WINNT 0x0100
#include <windows.h>
#include <urlmon.h>

#include "debug.h"

HRESULT WINAPI CORURL_CopyStgMedium(STGMEDIUM *pcstgmedSrc, STGMEDIUM *pstmedDest)
{
  Trace(TRACE_UNIMPLEMENTED, "CopyStgMedium");
  return 0;
}
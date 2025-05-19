#define _WIN32_WINNT 0x0100
#include <windows.h>

#include "debug.h"

ULONG WINAPI IPHLPAPI_GetAdaptersInfo(UINT *AdapterInfo, ULONG *SizePointer)
{
	Trace(TRACE_UNIMPLEMENTED, "GetAdaptersInfo");
  return 0;
}

ULONG WINAPI IPHLPAPI_GetNetworkParams(UINT *pFixedInfo, ULONG *pOutBufLen)
{
	Trace(TRACE_UNIMPLEMENTED, "GetNetworkParams");
  return 0;
}
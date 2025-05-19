#define _WIN32_WINNT 0x0100
#include <windows.h>

#include "debug.h"

BOOL WINAPI CORMS_DeleteColorTransform(HANDLE hxform)
{
	Trace(TRACE_UNIMPLEMENTED, "DeleteColorTransform");
	return FALSE;
}

// First DWORD should be PPROFILE
HANDLE WINAPI CORMS_OpenColorProfileA(DWORD *pProfile, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationMode)
{
	Trace(TRACE_UNIMPLEMENTED, "OpenColorProfileA");
	return NULL;
}

BOOL WINAPI CORMS_CloseColorProfile(HANDLE hProfile)
{
	Trace(TRACE_UNIMPLEMENTED, "CloseColorProfile");
	return FALSE;
}

HANDLE WINAPI CORMS_CreateColorTransformW(LPLOGCOLORSPACEW pLogColorSpace, HANDLE hDestProfile, HANDLE hTargetProfile, DWORD dwFlags)
{
	Trace(TRACE_UNIMPLEMENTED, "CreateColorTransformW");
	return FALSE;
}

// First DWORD should be BMINPUT, same for the one before bmoutput
BOOL WINAPI CORMS_TranslateBitmapBits(
HANDLE hColorTransform,
VOID *pSrcBits,
DWORD bmInput,
DWORD dwWidth,
DWORD dwHeight,
DWORD dwInputStride,
VOID *pDestBits,
DWORD bmOutput,
DWORD dwOutputStride,
BOOL *pfnCallBack,
LPARAM ulCallbackData)
{
	Trace(TRACE_UNIMPLEMENTED, "TranslateBitmapBits");
	return FALSE;
}
#define _WIN32_WINNT 0x0100

#include <stdio.h>
#include <windows.h>

#include "debug.h"

DWORD WINAPI CORKEL32_GetLastError()
{
  DWORD e = GetLastError();
  Trace(TRACE_PASSTHROUGH, "GetLastError: 0x%X", e);
  return e;
}

FARPROC WINAPI CORKEL32_GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  FARPROC f = GetProcAddress(hModule, lpProcName);
  char buffer[256];
  GetModuleFileNameA(hModule, buffer, 256);
  Trace((f) ? TRACE_PASSTHROUGH : TRACE_POTENTIAL_ERROR, "GetProcAddress: %s %s = %p", buffer, lpProcName, f);
  return f;
}

INT WINAPI CORKEL32_MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, INT cbMultiByte, LPWSTR lpWideCharStr, INT cchWideChar)
{
  INT r;

  r =  MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
  Trace(TRACE_PASSTHROUGH, "MultiByteToWideChar - CodePage = %u, flags = %x, result = %d", CodePage, dwFlags, r);

  return r;
}

INT WINAPI CORKEL32_WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, INT cchWideChar, LPSTR lpMultiByteStr, INT cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar)
{
  INT r;

  // Windows 95 doesn't support these flags and will throw an error if they're specified
  const unsigned short WC_ERR_INVALID_CHARS = 0x80;
  const unsigned short WC_NO_BEST_FIT_CHARS = 0x400;
  dwFlags &= ~WC_NO_BEST_FIT_CHARS;
  dwFlags &= ~WC_ERR_INVALID_CHARS;

  // Windows 95 doesn't appear to support UTF-8 conversion, so we fallback to the default multibyte codepage
  if (CodePage == CP_UTF8) {
    CodePage = CP_ACP;
  }

  r = WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cbMultiByte, lpDefaultChar, lpUsedDefaultChar);
  Trace(TRACE_PASSTHROUGH, "WideCharToMultiByte, r = %i, CodePage = %u, dwFlags = %u", r, CodePage, dwFlags);
  return r;
}

HMODULE WINAPI CORKEL32_LoadLibraryExA(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
{
  HMODULE h = LoadLibraryExA(lpLibFileName, hFile, dwFlags);
  Trace((h != NULL) ? TRACE_PASSTHROUGH : TRACE_POTENTIAL_ERROR, "LoadLibraryExA: %s - result: %p", lpLibFileName, h);
  return h;
}

HMODULE WINAPI CORKEL32_LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
{
  HMODULE h = LoadLibraryExW(lpLibFileName, hFile, dwFlags);
  Trace((h != NULL) ? TRACE_PASSTHROUGH : TRACE_POTENTIAL_ERROR, "LoadLibraryExW: %ls - result: %p", lpLibFileName, h);
  return h;
}

HANDLE WINAPI CORKEL32_CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
  /*LONG fnLen;
  char temp2[512];
  HANDLE h;
  DWORD le;*/

  Trace(TRACE_PASSTHROUGH, "CreateFileA");

  if (!strcmp(lpFileName, "\\\\.\\NDPHLPR.VXD")) {
    return (HANDLE) 0xCAFEBABE;
  }

  /*if (dwFlagsAndAttributes & FILE_FLAG_DELETE_ON_CLOSE) {
    sprintf(temp2, "lpFileName: %s, dwDesiredAccess: %x, dwShareMode: %x, lpSecurityAttributes: %p, dwCreationDisposition: %x, dwFlagsAndAttributes: %x, hTemplateFile: %x", lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    MessageBoxA(NULL, temp2, NULL, 0);
  }

  h = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

  if (dwFlagsAndAttributes & FILE_FLAG_DELETE_ON_CLOSE) {
    le = GetLastError();
    if (le) {
      sprintf(temp2, "CreateFileA Failed: 0x%X", le);
      MessageBoxA(0, temp2, 0, 0);
      SetLastError(le);
    }
  }*/

  return CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

DWORD WINAPI CORKEL32_GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize)
{
  DWORD r = GetEnvironmentVariableA(lpName, lpBuffer, nSize);
  Trace(TRACE_PASSTHROUGH, "GetEnvironmentVariableA - r = %u - %s = %s", r, lpName, lpBuffer);
  return r;
}

HMODULE WINAPI CORKEL32_LoadLibraryA(LPCSTR lpLibFileName)
{
  HMODULE h = LoadLibraryA(lpLibFileName);
  Trace((h != NULL) ? TRACE_PASSTHROUGH : TRACE_POTENTIAL_ERROR, "LoadLibraryA: %s - result: %p", lpLibFileName, h);
  return h;
}

HMODULE WINAPI CORKEL32_LoadLibraryW(LPCWSTR lpLibFileName)
{
  HMODULE h = LoadLibraryW(lpLibFileName);
  Trace((h != NULL) ? TRACE_PASSTHROUGH : TRACE_POTENTIAL_ERROR, "LoadLibraryW: %ls - result: %p", lpLibFileName, h);
  return h;
}

BOOL WINAPI CORKEL32_DeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize, LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped)
{
  BOOL e;

  /*char buf[512];
  sprintf(buf, "hDevice: 0x%p, dwIoControlCode: 0x%X, lpInBuffer: %p, nInBufferSize: 0x%X, lpOutBuffer: %p, nOutBufferSize: 0x%X, lpBytesReturned: %p, lpOverlapped: %p", hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped);
  MessageBoxA(0, buf, 0, 0);*/

  if (hDevice == (HANDLE) 0xCAFEBABE) {
    if (dwIoControlCode == 0x86427531) {
      *(DWORD*)lpOutBuffer = 0x40;
    } else {
      char buf[100];
      sprintf(buf, "Hijack 2: 0x%X", dwIoControlCode);
      MessageBoxA(0,buf,0,0);
    }

    return TRUE;
  }

  e = DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped);
  Trace(TRACE_PASSTHROUGH, "DeviceIoControl");

  /*if (!e) {
    DWORD le = GetLastError();

    sprintf(buf, "DeviceIoControl Failed: 0x%X", le);
    MessageBoxA(0, buf, 0, 0);

    SetLastError(le);
  }*/

  return e;
}

// Reimplemented
LONG WINAPI CORKEL32_InterlockedCompareExchange(LONG *dest,  LONG xchg,  LONG compare)
{
  LONG temp = *dest;

  // Passthrough if already implemented due to issues on 98 and NT
  // wait this doesn't even work, I guess you just have to passthrough in corkel32.def then
  typedef LONG (WINAPI *InterlockedCompareExchange_t)(LONG, LONG, LONG);
  InterlockedCompareExchange_t interlockedCompareExchange = (InterlockedCompareExchange_t) GetProcAddress(GetModuleHandleA("KERNEL32.DLL"), "InterlockedCompareExchange");
  
  if (interlockedCompareExchange) {
    return interlockedCompareExchange(dest, xchg, compare);
  }
  
  Trace(TRACE_FORCE_DONT_PRINT, "InterlockedCompareExchange");

  if (compare == *dest) {
    *dest = xchg;
  }

  return temp;
}

HANDLE WINAPI CORKEL32_CreateToolhelp32Snapshot(DWORD param_0, DWORD param_1)
{
  Trace(TRACE_UNIMPLEMENTED, "CreateToolhelp32Snapshot");
  // TODO: Stub
  return NULL;
}

BOOL WINAPI CORKEL32_IsDebuggerPresent()
{
  Trace(TRACE_IMPLEMENTED, "IsDebuggerPresent");
  return FALSE;
}

BOOL WINAPI CORKEL32_GetFileAttributesExA(LPCSTR name, GET_FILEEX_INFO_LEVELS level, LPVOID ptr)
{
  WIN32_FILE_ATTRIBUTE_DATA *data;
  HANDLE hFile;
  // wchar_t err[256]; // for debugging
  // memset(err, 0, 256); // for debugging

  Trace(TRACE_IMPLEMENTED, "GetFileAttributesExA - %s", name);
  
  // FILE_FLAG_BACKUP_SEMANTICS doesn't exist on 9x but is required to get an handle to directories, including SharedObjects
  // TODO: Find a way to get directory handles on 9x
  hFile = CreateFileA(name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
  data = ptr;
   if (hFile == INVALID_HANDLE_VALUE) {
    // FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), err, 255, NULL);
    // Trace(TRACE_DISABLE, "GetFileAttributesExA FindFirstFileA err - %1s", err);
    // Trace(TRACE_DISABLE, "GetFileAttributesExA FindFirstFileA name - %1s", name);
    return FALSE;
  }

  data->dwFileAttributes = GetFileAttributesA(name);
  GetFileTime(hFile, &data->ftCreationTime, &data->ftLastAccessTime, &data->ftLastWriteTime);
  data->nFileSizeLow = GetFileSize(hFile, &data->nFileSizeHigh);

  CloseHandle(hFile);

  return TRUE;
}

BOOL WINAPI CORKEL32_GetFileAttributesExW(LPCWSTR name, GET_FILEEX_INFO_LEVELS level, LPVOID ptr)
{
  WIN32_FILE_ATTRIBUTE_DATA *data;
  HANDLE hFile;
  // wchar_t err[256]; // for debugging
  // memset(err, 0, 256); // for debugging

  // Trace(TRACE_DISABLE, "GetFileAttributesExW - %ls", name);

  data = ptr;
  hFile = CreateFileW(name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
  if (hFile == INVALID_HANDLE_VALUE) {
	// FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), err, 255, NULL);
	// Trace(TRACE_DISABLE, "GetFileAttributesExW CreateFileW err - %1s", err);
	// Trace(TRACE_DISABLE, "GetFileAttributesExW CreateFileW name - %1s", name);
    return FALSE;
  }

  data->dwFileAttributes = GetFileAttributesW(name);
  GetFileTime(hFile, &data->ftCreationTime, &data->ftLastAccessTime, &data->ftLastWriteTime);
  data->nFileSizeLow = GetFileSize(hFile, &data->nFileSizeHigh);

  CloseHandle(hFile);

  return TRUE;
}

DWORD WINAPI CORKEL32_GetLongPathNameA(LPCSTR lpszShortPath, LPSTR lpszLongPath, DWORD cchBuffer)
{
  strncpy(lpszLongPath, lpszShortPath, cchBuffer);
  Trace(TRACE_IMPLEMENTED, "GetLongPathNameA - lpszShortPath: %s, lpszLongPath: %s, cchBuffer: 0x%X", lpszShortPath, lpszLongPath, cchBuffer);
  return 0;
}

DWORD WINAPI CORKEL32_GetLongPathNameW(LPCWSTR lpszShortPath, LPWSTR lpszLongPath, DWORD cchBuffer)
{
  wcsncpy(lpszLongPath, lpszShortPath, cchBuffer);
  Trace(TRACE_IMPLEMENTED, "GetLongPathNameW - lpszShortPath: %ls, lpszLongPath: %ls, cchBuffer: 0x%X", lpszShortPath, lpszLongPath, cchBuffer);
  return 0;
}

BOOL WINAPI CORKEL32_EnumDateFormatsExW(LPVOID param_0, LCID param_1, DWORD param_2)
{
  Trace(TRACE_UNIMPLEMENTED, "EnumDateFormatsExW");
  return FALSE;
}

DWORD WINAPI CORKEL32_SetThreadIdealProcessor(HANDLE param_0, DWORD param_1)
{
  Trace(TRACE_UNIMPLEMENTED, "SetThreadIdealProcessor");
  return 0;
}

INT WINAPI CORKEL32_GetCalendarInfoA(LCID param_0, DWORD param_1, DWORD param_2, LPSTR param_3, INT param_4, LPDWORD param_5)
{
  Trace(TRACE_UNIMPLEMENTED, "GetCalendarInfoA");
  return 0;
}

INT WINAPI CORKEL32_GetCalendarInfoW(LCID param_0, DWORD param_1, DWORD param_2, LPWSTR param_3, INT param_4, LPDWORD param_5)
{
  Trace(TRACE_UNIMPLEMENTED, "GetCalendarInfoW");
  return 0;
}

BOOL WINAPI CORKEL32_SetProcessAffinityMask(HANDLE param_0, DWORD param_1)
{
  Trace(TRACE_UNIMPLEMENTED, "SetProcessAffinityMask");
  return FALSE;
}

DWORD WINAPI CORKEL32_SignalObjectAndWait(HANDLE param_0, HANDLE param_1, DWORD param_2, BOOL param_3)
{
  Trace(TRACE_UNIMPLEMENTED, "SignalObjectAndWait");
  return 0;
}

BOOL WINAPI CORKEL32_SwitchToThread()
{
  Trace(TRACE_UNIMPLEMENTED, "SwitchToThread");
  return FALSE;
}

BOOL WINAPI CORKEL32_IsProcessorFeaturePresent(DWORD ProcessorFeature)
{
  Trace(TRACE_IMPLEMENTED, "IsProcessorFeaturePresent: %X", ProcessorFeature);
  return FALSE;
}

UINT WINAPI CORKEL32_GetSystemWindowsDirectoryW( LPWSTR path, UINT count )
{
  Trace(TRACE_IMPLEMENTED, "GetSystemWindowsDirectoryW");
  return GetWindowsDirectoryW( path, count );
}

BOOL WINAPI CORKEL32_InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION crit, DWORD count)
{
  Trace(TRACE_IMPLEMENTED, "InitializeCriticalSectionAndSpinCount: %p, 0x%X", crit, count);

  InitializeCriticalSection(crit);

  // Windows 95 doesn't support spincounts so we ignore here
  //crit->Reserved = count & ~0x80000000;

  return TRUE;
}

// VOID pointer should be PTIMERAPCROUTINE
BOOL WINAPI CORKEL32_SetWaitableTimer(HANDLE hTimer, const LARGE_INTEGER *lpDueTime, LONG lPeriod, VOID *pfnCompletionRoutine, LPVOID lpArgToCompletionRoutine, BOOL fResume)
{
  // TODO: Stub
  Trace(TRACE_UNIMPLEMENTED, "SetWaitableTimer");
  return FALSE;
}

HANDLE WINAPI CORKEL32_CreateWaitableTimerA(LPSECURITY_ATTRIBUTES lpTimerAttributes, BOOL bManualReset, LPCWSTR lpTimerName)
{
  // TODO: Stub
  Trace(TRACE_UNIMPLEMENTED, "CreateWaitableTimerA");
  return NULL;
}

void WINAPI CORKEL32_GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime)
{
  // Only Windows 95 lacks this function so if we have it, we passthrough.
  // Otherwise, just throw an error.

  typedef void (WINAPI *GetSystemTimeAsFileTime_t)(LPFILETIME);
  GetSystemTimeAsFileTime_t getSystemTimeAsFileTime = (GetSystemTimeAsFileTime_t) GetProcAddress(GetModuleHandleA("KERNEL32.DLL"), "GetSystemTimeAsFileTime");

  if (getSystemTimeAsFileTime) {
	Trace(TRACE_IMPLEMENTED, "GetSystemTimeAsFileTime");
    getSystemTimeAsFileTime(lpSystemTimeAsFileTime);
  } else {
	Trace(TRACE_UNIMPLEMENTED, "GetSystemTimeAsFileTime");
  }
}

BOOL WINAPI CORKEL32_SetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod)
{
	// Shamelessly stolen from KernelEx
	DWORD lasterr = GetLastError();
	Trace(TRACE_UNIMPLEMENTED, "SetFilePointerEx");
	if ((liDistanceToMove.LowPart = SetFilePointer(hFile, liDistanceToMove.LowPart, &liDistanceToMove.HighPart, dwMoveMethod)) == 0xFFFFFFFF && GetLastError() != NO_ERROR)
	{
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}
	if (lpNewFilePointer) *lpNewFilePointer = liDistanceToMove;
	SetLastError(lasterr);
	return TRUE;
}

BOOL WINAPI CORKEL32_GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize)
{
	// Shamelessly stolen from KernelEx
	DWORD h, l, lasterr;
	Trace(TRACE_UNIMPLEMENTED, "GetFileSizeEx");
	lasterr = GetLastError();
	l = GetFileSize(hFile, &h);
	if (l == INVALID_FILE_SIZE && GetLastError() != NO_ERROR)
	{
		return FALSE;
	} else  {
		lpFileSize->HighPart = h;
		lpFileSize->LowPart = l;
	}
	SetLastError(lasterr);
	return TRUE;
}

// For VPC 4.1
BOOL WINAPI CORKEL32_CancelIo(HANDLE hFile)
{
  Trace(TRACE_UNIMPLEMENTED, "CancelIo");
  return FALSE;
}

// For VPC
LONG WINAPI CORKEL32_InterlockedExchangeAdd(LONG *Addend, LONG Value)
{
  Trace(TRACE_IMPLEMENTED, "InterlockedExchangeAdd");
  Addend = Addend + Value;
  return *Addend;
}

DWORD WINAPI CORKEL32_GetVersion()
{
  Trace(TRACE_IMPLEMENTED, "GetVersion");
  // Lie about being on Windows ME (last 9x-based windows version)
  return (DWORD)( (1    << 30)  | // Platform ID (1 = 9x, 2 = NT)
                  (3000 << 16)  | // Build number (300 is Windows ME RTM)
                  (90   << 8)   | // Minor version (Windows ME is 4.90, so minor version = 90)
                   4);            // Major version (4 for 95, 98, ME and NT 4)
}

BOOL WINAPI CORKEL32_GetVersionExA(LPOSVERSIONINFOA lpVersionInfo)
{
  Trace(TRACE_IMPLEMENTED, "GetVersionExA");
  lpVersionInfo->dwOSVersionInfoSize   = sizeof(OSVERSIONINFOEXA);

  // ME's version number is 4.90.3000
  lpVersionInfo->dwMajorVersion   = (DWORD)4;
  lpVersionInfo->dwMinorVersion   = (DWORD)90;
  lpVersionInfo->dwBuildNumber    = (DWORD)3000;

  // 1 is 9x, 2 is NT
  lpVersionInfo->dwPlatformId     = (DWORD)1;

  return TRUE;
}


HMODULE WINAPI CORKEL32_GetModuleHandleW(LPCWSTR lpModuleName)
{
  Trace(TRACE_UNIMPLEMENTED, "GetModuleHandleW - %s", lpModuleName);

  // We assume that it's asking for KERNEL32.DLL.
  // This should be enough since the only non-KERNEL32
  // module which Flash 10 tries to get the handle
  // for is "mscoree.dll" when closing.
  return GetModuleHandleA((LPCSTR)"KERNEL32.DLL");
}
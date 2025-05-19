#define _WIN32_WINNT 0x0100
#include <windows.h>

#include "debug.h"

typedef struct tagWINDOWINFO {
  DWORD cbSize;
  RECT  rcWindow;
  RECT  rcClient;
  DWORD dwStyle;
  DWORD dwExStyle;
  DWORD dwWindowStatus;
  UINT  cxWindowBorders;
  UINT  cyWindowBorders;
  ATOM  atomWindowType;
  WORD  wCreatorVersion;
} WINDOWINFO, *PWINDOWINFO, *LPWINDOWINFO;

//
// Reimplementations
//

DWORD WINAPI CORUSR_MsgWaitForMultipleObjects(DWORD nCount, const HANDLE* pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask)
{
  Trace(TRACE_IMPLEMENTED, "MsgWaitForMultipleObjects");
  return WaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds);
}

DWORD WINAPI CORUSR_MsgWaitForMultipleObjectsEx(DWORD nCount, const HANDLE* pHandles, DWORD dwMilliseconds, DWORD dwWakeMask, DWORD dwFlags)
{
  Trace(TRACE_IMPLEMENTED, "MsgWaitForMultipleObjectsEx");
  return WaitForMultipleObjectsEx(nCount, pHandles, (dwFlags & MWMO_WAITALL), dwMilliseconds, (dwFlags & MWMO_ALERTABLE));
}

INT WINAPIV CORUSR_wsprintfW(LPWSTR param_0, LPCWSTR param_1, ...)
{
  INT r;
  va_list args;

  Trace(TRACE_IMPLEMENTED, "wsprintfW");

  va_start(args, param_1);

  r = wvsprintfW(param_0, param_1, args);

  va_end(args);

  return r;
}

void WINAPI CORUSR_NotifyWinEvent(DWORD event, HWND  hwnd, LONG  idObject, LONG  idChild)
{
  // Only Windows 95 lacks this function so if we have it, we passthrough.
  // Otherwise, just do nothing.

  typedef void (WINAPI *NotifyWinEvent_t)(DWORD, HWND, LONG, LONG);
  NotifyWinEvent_t notifyWinEvent = (NotifyWinEvent_t) GetProcAddress(GetModuleHandleA("USER32.DLL"), "NotifyWinEvent");
  
  Trace(TRACE_IMPLEMENTED, "NotifyWinEvent");

  if (notifyWinEvent) {
    notifyWinEvent(event, hwnd, idObject, idChild);
  }
}

UINT WINAPI CORUSR_SendInput(UINT cInputs, WORD pInputs, int cbSize)
{
  Trace(TRACE_UNIMPLEMENTED, "SendInput");
  return 0;
}

// Normally HMONITOR but that's just an HANDLE
HANDLE WINAPI CORUSR_MonitorFromWindow(HWND hwnd, DWORD dwFlags)
{
  Trace(TRACE_UNIMPLEMENTED, "MonitorFromWindow");
  return 0;
}

// LPRECT should be LPMONITORINFO
BOOL WINAPI CORUSR_GetMonitorInfoA(HANDLE hMonitor, LPRECT lpmi)
{
	Trace(TRACE_UNIMPLEMENTED, "GetMonitorInfoA");
	return FALSE;
}

BOOL WINAPI CORUSR_EnumDisplaySettingsA(LPCSTR lpszDeviceName, DWORD iModeNum, DEVMODEA *lpDevMode)
{
	Trace(TRACE_UNIMPLEMENTED, "EnumDisplaySettingsA");
	return FALSE;
}

BOOL WINAPI CORUSR_GetWindowInfo(HWND hwnd, PWINDOWINFO pmi)
{
	Trace(TRACE_UNIMPLEMENTED, "GetWindowInfo");
	return FALSE;
}

// For VPC 4.1
// LPCSTR should be LPTRACKMOUSEEVENT
BOOL WINAPI CORUSR_TrackMouseEvent(LPCSTR lpEventTrack)
{
	Trace(TRACE_UNIMPLEMENTED, "TrackMouseEvent");
	return FALSE;
}
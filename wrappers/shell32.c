#define _WIN32_WINNT 0x0100
#include <windows.h>
#include <shlobj.h>

#include "debug.h"

//
// Reimplementations
//

HRESULT WINAPI CORSHEL_SHGetSpecialFolderLocation(HWND hwnd, int csidl, ITEMIDLIST *ppidl)
{
  Trace(TRACE_UNIMPLEMENTED, "SHGetSpecialFolderLocation");
  return 0;
}

// Yes, I know, having it be an UINT is illegal
UINT WINAPI CORSHEL_SHBrowseForFolderA(LPBROWSEINFOA lpbi)
{
  Trace(TRACE_UNIMPLEMENTED, "SHBrowseForFolderA");
  return 0;
}

BOOL WINAPI CORSHEL_SHGetPathFromIDListA(ITEMIDLIST pidl, LPSTR pszPath)
{
  Trace(TRACE_UNIMPLEMENTED, "SHGetPathFromIDListA");
  return FALSE;
}

// Second UINT is supposed to be PAPPBARDATA
UINT WINAPI CORSHEL_SHAppBarMessage(DWORD dwMessage, UINT *pData)
{
  Trace(TRACE_UNIMPLEMENTED, "SHAppBarMessage");
  return 0;
}


UINT WINAPI CORSHEL_DragQueryFileA(HDROP hDrop, UINT iFile, CHAR lpszFile, UINT cch)
{
  Trace(TRACE_UNIMPLEMENTED, "DragQueryFileA");
  return 0;
}

UINT WINAPI CORSHEL_DragQueryFileW(HDROP hDrop, UINT iFile, CHAR lpszFile, UINT cch)
{
  Trace(TRACE_UNIMPLEMENTED, "DragQueryFileW");
  return 0;
}

void WINAPI CORSHEL_DragAcceptFiles(HWND hWnd, BOOL fAccept)
{
  typedef void (WINAPI *DragAcceptFiles_t)(HWND, BOOL);
  DragAcceptFiles_t dragAcceptFiles = (DragAcceptFiles_t) GetProcAddress(GetModuleHandleA("SHELL32.DLL"), "DragAcceptFiles");
  if (dragAcceptFiles) {
    return dragAcceptFiles(hWnd, fAccept);
  }

  // This is why drag & drop doesn't work on FP10
  Trace(TRACE_UNIMPLEMENTED, "DragAcceptFiles");
}
#define _WIN32_WINNT 0x0100
#include <windows.h>
#include <shlobj.h>

#include "debug.h"

//
// Reimplementations
//

int WINAPI WS2_32_getsockopt()
{
  Trace(TRACE_UNIMPLEMENTED, "getsockopt");
  return 0;
}

int WINAPI WS2_32_ioctlsocket()
{
  Trace(TRACE_UNIMPLEMENTED, "ioctlsocket");
  return 0;
}

int WINAPI WS2_32_select()
{
  Trace(TRACE_UNIMPLEMENTED, "select");
  return 0;
}

int WINAPI WS2_32_setsockopt()
{
  Trace(TRACE_UNIMPLEMENTED, "setsockopt");
  return 0;
}

BOOL WINAPI WS2_32_WSACloseEvent()
{
  Trace(TRACE_UNIMPLEMENTED, "WSACloseEvent");
  return FALSE;
}

int WINAPI WS2_32_WSACreateEvent()
{
  Trace(TRACE_UNIMPLEMENTED, "WSACreateEvent");
  return 0;
}

int WINAPI WS2_32_WSAEnumNetworkEvents()
{
  Trace(TRACE_UNIMPLEMENTED, "WSAEnumNetworkEvents");
  return 0;
}

int WINAPI WS2_32_WSAEventSelect()
{
  Trace(TRACE_UNIMPLEMENTED, "WSAEventSelect");
  return 0;
}

int WINAPI WS2_32_WSAIoctl()
{
  Trace(TRACE_UNIMPLEMENTED, "WSAIoctl");
  return 0;
}

int WINAPI WS2_32_WSAStartup()
{
  Trace(TRACE_UNIMPLEMENTED, "WSAStartup");
  return 0;
}

int WINAPI WS2_32_WSACleanup()
{
  Trace(TRACE_UNIMPLEMENTED, "WSACleanup");
  return 0;
}

BOOL WINAPI WS2_32_WSAResetEvent()
{
  Trace(TRACE_UNIMPLEMENTED, "WSAResetEvent");
  return FALSE;
}

BOOL WINAPI WS2_32_WSASetEvent()
{
  Trace(TRACE_UNIMPLEMENTED, "WSASetEvent");
  return FALSE;
}

DWORD WINAPI WS2_32_WSAWaitForMultipleEvents()
{
  Trace(TRACE_UNIMPLEMENTED, "WSAWaitForMultipleEvents");
  return 0;
}

void WINAPI WS2_32_freeaddrinfo()
{
	Trace(TRACE_UNIMPLEMENTED, "freeaddrinfo");
	return;
}

int WINAPI WS2_32_getaddrinfo()
{
	Trace(TRACE_UNIMPLEMENTED, "getaddrinfo");
	return 0;
}

int WINAPI WS2_32_WSAAddressToStringA()
{
	Trace(TRACE_UNIMPLEMENTED, "WSAAddressToStringA");
	return 0;
}

int WINAPI WS2_32_WSASocketA()
{
	Trace(TRACE_UNIMPLEMENTED, "WSASocketA");
	return 0;
}

int WINAPI WS2_32_accept()
{
	Trace(TRACE_UNIMPLEMENTED, "accept");
	return 0;
}

int WINAPI WS2_32_bind()
{
	Trace(TRACE_UNIMPLEMENTED, "bind");
	return 0;
}

int WINAPI WS2_32_closesocket()
{
	Trace(TRACE_UNIMPLEMENTED, "closesocket");
	return 0;
}

int WINAPI WS2_32_connect()
{
	Trace(TRACE_UNIMPLEMENTED, "connect");
	return 0;
}

int WINAPI WS2_32_getpeername()
{
	Trace(TRACE_UNIMPLEMENTED, "getpeername");
	return 0;
}
int WINAPI WS2_32_getsockname()
{
	Trace(TRACE_UNIMPLEMENTED, "getsockname");
	return 0;
}

long WINAPI WS2_32_htonl()
{
	Trace(TRACE_UNIMPLEMENTED, "htonl");
	return 0;
}

short WINAPI WS2_32_htons()
{
	Trace(TRACE_UNIMPLEMENTED, "htons");
	return 0;
}

long WINAPI WS2_32_inet_addr(char *cp)
{
	Trace(TRACE_UNIMPLEMENTED, "inet_addr");
	return 0;
}

char WINAPI WS2_32_inet_ntoa()
{
	Trace(TRACE_UNIMPLEMENTED, "inet_ntoa");
	return NULL;
}
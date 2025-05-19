#define _WIN32_WINNT 0x0100
#include <windows.h>

#include "debug.h"

BOOL WINAPI CRYPT32_CertFreeCertificateContext()
{
	Trace(TRACE_UNIMPLEMENTED, "CertFreeCertificateContext");
	// TODO: Stub
	return FALSE;
}

BOOL WINAPI CRYPT32_CertVerifySubjectCertificateContext()
{
	Trace(TRACE_UNIMPLEMENTED, "CertVerifySubjectCertificateContext");
	// TODO: Stub
	return FALSE;
}

HANDLE WINAPI CRYPT32_CertFindCertificateInStore()
{
	Trace(TRACE_UNIMPLEMENTED, "CertFindCertificateInStore");
	// TODO: Stub
	return NULL;
}

HANDLE WINAPI CRYPT32_CertCreateCertificateContext(DWORD dwCertEncodingType, BYTE *pbCertEncoded, DWORD cbCertEncoded)
{
	Trace(TRACE_UNIMPLEMENTED, "CertCreateCertificateContext");
	// TODO: Stub
	return NULL;
}

HANDLE WINAPI CRYPT32_CryptGetMessageCertificates()
{
	Trace(TRACE_UNIMPLEMENTED, "CryptGetMessageCertificates");
	// TODO: Stub
	return NULL;
}

BOOL WINAPI CRYPT32_CryptVerifyMessageSignature()
{
	Trace(TRACE_UNIMPLEMENTED, "CryptVerifyMessageSignature");
	// TODO: Stub
	return TRUE;
}

VOID WINAPI CRYPT32_CertCloseStore()
{
	Trace(TRACE_UNIMPLEMENTED, "CertCloseStore");
	// TODO: Stub
}

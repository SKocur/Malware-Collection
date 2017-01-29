// Client code
// Author: Szymon Kocur

#include <stdio.h>
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char * argv[])
{
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
	service.sin_port = htons(27015);

	if (connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR) {
		printf("Failed to connect.\n");
		getchar();
		WSACleanup();
		return 1;
	}

	char recvbuf[100] = "";
	
	while (1) {
		char sendbuf[100];
		std::cout << "You: ";
		std::cin >> sendbuf;
		send(mainSocket, sendbuf, 100, 0);
		recv(mainSocket, recvbuf, 100, 0);
		std::cout << "Server: " << recvbuf << std::endl;
	}

	getchar();
	return 0;
}

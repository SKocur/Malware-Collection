// Server code
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

	std::cout << "Ip of client: ";
	char ip[50];
	std::cin >> ip;

	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);
	service.sin_port = htons(27015);

	int bindSocket = bind(mainSocket, (SOCKADDR *)& service, sizeof(service));

	if (listen(mainSocket, 1) == SOCKET_ERROR) {
		printf("Error: listening on socket.\n");
		getchar();
		return 1;
	}

	SOCKET acceptSocket = SOCKET_ERROR;
	printf("Waiting for client to connect ... \n");

	while (acceptSocket == SOCKET_ERROR) {
		acceptSocket = accept(mainSocket, NULL, NULL);
	}

	printf("Client connected!\n");
	mainSocket = acceptSocket;

	char recvbuf[100] = "";

	while (1) {
		recv(mainSocket, recvbuf, 100, 0);
		std::cout << "Client: " << recvbuf << std::endl;
		char sendbuf[100];
		std::cout << "You: ";
		std::cin >> sendbuf;
		send(mainSocket, sendbuf, 100, 0);
	}

	getchar();
	return 0;
}

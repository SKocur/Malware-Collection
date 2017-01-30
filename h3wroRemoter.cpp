// Server code (command terminal)
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

	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("0.0.0.0");
	service.sin_port = htons(13099);

	bind(mainSocket, (SOCKADDR *)& service, sizeof(service));

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

	while (1) {
		char sendbuf[400];
		std::cout << "Command: ";
		std::cin >> sendbuf;

		// Because of terminating input on white spaces (std::cin), code below swap ` with blank space
		char message[400];
		for(int i = 0; i < 400; i++){
		    if(sendbuf[i] == '`'){
                message[i] = ' ';
                continue;
		    }
            message[i] = sendbuf[i];
		}
		send(mainSocket, message, 400, 0);
        std::cout << message << std::endl;
	}

	getchar();
	return 0;
}

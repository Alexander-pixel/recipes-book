#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <fstream>

#pragma comment (lib, "Ws2_32.lib")

class Server
{
	const char* DEFAULT_PORT;
	SOCKET ListenSocket, ClientSocket;
	struct addrinfo* result, hints;
	int code_error;

public:
	Server();

	void ConnectToClient();

	void SendMessageToClient();

	std::string RecieveMessageFromClient();

	~Server();
};

#include "Server.h"

int main()
{
	try
	{
		Server server;
		server.ConnectToClient();

		server.SendMessageToClient();
		//cout << "Client: " << server.RecieveMessageFromClient() << endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

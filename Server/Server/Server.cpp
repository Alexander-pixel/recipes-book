//Server.cpp

#include "Server.h"

Server::Server()
{
    DEFAULT_PORT = "27015";
    ListenSocket = INVALID_SOCKET;
    ClientSocket = INVALID_SOCKET;
    addrinfo* result = NULL;

    WSADATA wsaData;
    code_error = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (code_error != 0)
    {
        throw std::runtime_error("WSAStartup failed with error: " + std::to_string(code_error));
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET; // AF_INET PF_INET
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    std::cout << "Server is ready for connections." << std::endl;
}

void Server::ConnectToClient()
{
    // Resolve the server address and port
    code_error = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (code_error != 0)
    {
        WSACleanup();
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(code_error));
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET)
    {
        freeaddrinfo(result);
        WSACleanup();
        throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()));
    }

    // Setup the TCP listening socket
    code_error = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (code_error == SOCKET_ERROR)
    {
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        throw std::runtime_error("bind failed with error: " + std::to_string(WSAGetLastError()));
    }

    freeaddrinfo(result);

    code_error = listen(ListenSocket, SOMAXCONN);
    if (code_error == SOCKET_ERROR)
    {
        closesocket(ListenSocket);
        WSACleanup();
        throw std::runtime_error("listen failed with error: " + std::to_string(WSAGetLastError()));
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET)
    {
        closesocket(ListenSocket);
        WSACleanup();
        throw std::runtime_error("accept failed with error: " + std::to_string(WSAGetLastError()));
    }

    std::cout << "Connection with client is successful." << std::endl;

    // No longer need server socket
    closesocket(ListenSocket);
}

void Server::SendMessageToClient()
{
    std::string buf;
    std::fstream fs("list_server.json");
    std::string result;

    const char* message{};
    if (fs.is_open())
    {
        while (getline(fs, buf))
        {
            result += buf;
        }
        
        message = result.c_str();

        code_error = send(ClientSocket, message, (int)strlen(message), 0);
        if (code_error == SOCKET_ERROR)
        {
            closesocket(ClientSocket);
            WSACleanup();
            throw std::runtime_error("send failed with error: " + std::to_string(WSAGetLastError()));
        }
        std::cout << "Message has been successfully send to client." << std::endl;
    }
    fs.close();
}

std::string Server::RecieveMessageFromClient()
{
    const unsigned int MAX_BUF_LENGTH = 4096;
    std::vector<char> buffer(MAX_BUF_LENGTH);
    std::string result;

    int bytesReceived = 0;
    do
    {
        bytesReceived = recv(ClientSocket, &buffer[0], buffer.size(), 0);

        if (bytesReceived < 0)
        {
            closesocket(ClientSocket);
            WSACleanup();
            throw std::runtime_error("recv failed with error: " + std::to_string(WSAGetLastError()));
        }
        else
        {
            result.append(buffer.cbegin(), buffer.cbegin() + bytesReceived);
        }
    } while (bytesReceived == MAX_BUF_LENGTH);

    std::cout << "Client send message on server. Server recieved message." << std::endl;

    std::ofstream fs("list_of_recipes.json");
    if (fs.is_open())
    {
        fs << result;
    }
    fs.close();

    return result;
}

Server::~Server()
{
    closesocket(ClientSocket);
    WSACleanup();
}
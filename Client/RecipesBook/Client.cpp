#include "Client.h"

Client::Client()
{
    DEFAULT_PORT = "27015";
    ADD_SERV = "127.0.0.1";
    ConnectSocket = INVALID_SOCKET;
    addrinfo* result = NULL, * ptr = NULL;
    WSADATA wsaData;

    code_error = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (code_error != 0)
    {
        throw std::runtime_error("WSAStartup failed with error: " + std::to_string(code_error));
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // AF_UNSPEC PF_INET
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    std::cout << "Client is connecting to server ..." << std::endl;
}

void Client::ConnectToServer()
{
    code_error = getaddrinfo(ADD_SERV, DEFAULT_PORT, &hints, &result);
    if (code_error != 0)
    {
        WSACleanup();
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(code_error));
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET)
        {
            WSACleanup();
            throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()));
        }

        // Connect to server.
        code_error = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (code_error == SOCKET_ERROR)
        {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET)
    {
        WSACleanup();
        throw std::runtime_error("Unable to connect to server!");
    }

    std::cout << "Client connected to server successfully." << std::endl;
}

void Client::SendMessageToServer()
{
    // connecting to server
    ConnectToServer();

    std::string sendbuf;
    std::string buf;

    std::fstream fs("list_of_recipes.json");

    if (fs.is_open())
    {
        while (!fs.eof())
        {
            getline(fs, buf);
            sendbuf += buf;
        }
        const char* message = sendbuf.c_str();
        code_error = send(ConnectSocket, message, (int)strlen(message), 0);
        if (code_error == SOCKET_ERROR)
        {
            closesocket(ConnectSocket);
            WSACleanup();
            throw std::runtime_error("send failed with error: " + std::to_string(WSAGetLastError()));
        }

        std::cout << "Message from client to server has been sent successfully." << std::endl;
    }
    else
    {
        MessageBox::Show("File is not open");
    }
    fs.close();
}

std::string Client::RecieveMessageFromServer()
{
    // connecting to server
    ConnectToServer();

    const unsigned int MAX_BUF_LENGTH = 4096;
    std::vector<char> buffer(MAX_BUF_LENGTH);
    std::string result;

    int bytesReceived = 0;
    do
    {
        bytesReceived = recv(ConnectSocket, &buffer[0], buffer.size(), 0);

        if (bytesReceived < 0)
        {
            throw std::runtime_error("recv failed with error: " + std::to_string(WSAGetLastError()));
        }
        else
        {
            result.append(buffer.cbegin(), buffer.cbegin() + bytesReceived);
        }
    } while (bytesReceived == MAX_BUF_LENGTH);

    std::cout << "Message from server to client has been recieved successfully." << std::endl;

    std::fstream fs("list_of_recipes.json");
    if (fs.is_open())
    {
        fs << result;
    }
    fs.close();

    return result;
}

Client::~Client()
{
    closesocket(ConnectSocket);
    WSACleanup();
}
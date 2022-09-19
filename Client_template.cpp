#include "head.hpp"

SOCKET Connection;

void close()
{
    closesocket(Connection);
}

void ClientHandler()
{
    int msg_size;
    while (true)
    {
        recv(Connection, (char *)&msg_size, sizeof(int), NULL);
        char *msg = new char[msg_size + 1];
        msg[msg_size] = '\0';
        recv(Connection, msg, msg_size, NULL);
        std::cout << msg << std::endl;
        delete[] msg;
    }
}

int main(int argc, char *argv[])
{
    atexit(close);
    // WSAStartup
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR *)&addr, sizeof(addr)) != 0)
    {
        std::cout << "Error: failed connect to server.\n";
        return 1;
    }
    std::cout << "Connected!\n";

    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

    std::string msg1;
    while (true)
    {
        std::getline(std::cin, msg1);
        int msg_size = msg1.size();
        send(Connection, (char *)&msg_size, sizeof(int), NULL);
        send(Connection, msg1.c_str(), msg_size, NULL);
        Sleep(10);
    }

    system("pause");
    return 0;
}
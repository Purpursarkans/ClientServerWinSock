#include "head.hpp"

const int SOCKET_COUNTER = 5;
int TotalSocket = 0;

SOCKET s;
WSADATA ws;
SOCKADDR_IN sa;

void sockInit()
{
    memset(&sa, 0, sizeof(sa));
    WSAStartup(MAKEWORD(2, 2), &ws);
    s = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_port = htons(1111);
}

void close() { closesocket(s); }

int main()
{
    atexit(close);

    sockInit();

    char c;
    std::cout << "s - server\nc - client" << std::endl;
    std::cin >> c;

    if (c == 'c') { Client(s, sa); }
    if (c == 's') { Server(s, sa, SOCKET_COUNTER, TotalSocket); }

    system("pause");
    return 0;
}
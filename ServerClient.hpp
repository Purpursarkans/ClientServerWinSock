#ifndef SERVER_CLIENT_HPP
#define SERVER_CLIENT_HPP

#include "head.hpp"

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

#endif
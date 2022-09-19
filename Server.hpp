#ifndef SERVER_HPP
#define SERVER_HPP

#include "head.hpp"

void Server()
{
    bind(s, (sockaddr *)&sa, sizeof(sa));

    listen(s, 100);

    SOCKET ClientSocket;
    SOCKADDR_IN ClientAddr;
    int ClientAddrSize = sizeof(ClientAddr);

    while (ClientSocket = accept(s, (sockaddr *)&ClientAddr, &ClientAddrSize))
    {
        std::cout << "connection ok" << std::endl;
    }
}

#endif
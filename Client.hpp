#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "head.hpp"

void Client(SOCKET &s, SOCKADDR_IN &sa)
{
    sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if(connect(s, (sockaddr *)&sa, sizeof(sa)) != 0)
    {
        std::cout << "Error: failed connect to server.\n";
        exit(1);
    }

    int SockControl = 0;

    while(true)
    {
        recv(s, (char *)&SockControl, sizeof(int), NULL);
        switch(SockControl)
        {
            case 1:
                std::cout << "one" << std::endl;
                break;
            default:
                std::cout << "error" << std::endl;
        }
    }
}

#endif
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "head.hpp"

void Client(SOCKET &s, SOCKADDR_IN &sa)
{
    sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    connect(s, (sockaddr *)&sa, sizeof(sa));
}

#endif
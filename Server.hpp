#ifndef SERVER_HPP
#define SERVER_HPP

#include "head.hpp"

//const int SOCKET_COUNTERS = 5;
//int TotalSockets = 0;

int SockControl = 1;

SOCKET *ClientSockets;

struct sdata
{
    SOCKET *ClientSockets2;
    int TotalSocket2;
};

void CommandSend(sdata data)
{
    while (true)
    {
        for (int i = 0; i < data.TotalSocket2; i++)
        {
            std::cout << "Enter command: ";
            std::cin >> SockControl;
            std::cout << (send(data.ClientSockets2[i], (char *)&SockControl, sizeof(int), 0)) << std::endl;
        }
    }
}
void Server(SOCKET &s, SOCKADDR_IN &sa, int SOCKET_COUNTERS, int TotalSockets)
{
    ClientSockets = new SOCKET[SOCKET_COUNTERS];

    bind(s, (sockaddr *)&sa, sizeof(sa));

    listen(s, 100);

    SOCKET ClientSocket;
    SOCKADDR_IN ClientAddr;
    int ClientAddrSize = sizeof(ClientAddr);

    for (int i = 0; i < SOCKET_COUNTERS; i++)
    {
        ClientSocket = accept(s, (sockaddr *)&ClientAddr, &ClientAddrSize);
        if (ClientSocket == 0)
        {
            std::cout << "Error #2\n";
        }
        else
        {
            std::cout << "connection ok" << std::endl;
            ClientSockets[i] = ClientSocket;
            TotalSockets++;

            sdata data;

            data.ClientSockets2 = ClientSockets;
            data.TotalSocket2 = TotalSockets;

            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CommandSend, (LPVOID)(&data), NULL, NULL);
        }
    }
    delete[] ClientSockets;
}

#endif
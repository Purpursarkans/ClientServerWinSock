#include "head.hpp"

int main()
{
    WSADATA ws;
    WSAStartup(MAKEWORD(2, 2), &ws);

    SOCKET s;
    s = socket(AF_INET, SOCK_STREAM, 0);

    SOCKADDR_IN sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1111);

    char c;
    std::cout << "s - server\nc - client" << std::endl;

    std::cin >> c;

    if (c == 'c')
    {
        sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

        connect(s, (sockaddr *)&sa, sizeof(sa));
    }

    if (c == 's')
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

        std::cout << (ClientSocket == accept(s, (sockaddr *)&ClientAddr, &ClientAddrSize)) << std::endl;
    }

    system("pause");

    closesocket(s);

    return 0;
}
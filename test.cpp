#include "head.hpp"

void close()
{
    closesocket(s);
}

int main()
{
    atexit(close);
    sockInit();

    char c;
    std::cout << "s - server\nc - client" << std::endl;
    std::cin >> c;

    if (c == 'c') { Client(); }
    if (c == 's') { Server(); }

    system("pause");

    return 0;
}
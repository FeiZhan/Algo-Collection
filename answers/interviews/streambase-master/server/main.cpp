#include <iostream>
#include <conio.h>

#include <Exception.h>
#include <Server.h>

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
    Server server;
    server.start();

        return 0;
    } catch (Exception &e)
    {
        cerr << e.what() << endl;
        _getch();
    }
    return -1;
}

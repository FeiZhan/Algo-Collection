#include <iostream>
#include <conio.h>

#include <Exception.h>
#include <Client.h>

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        bool async = false;
        if (argc > 1 && string(argv[1]) == "async") {
            async = true;
        }
        Client client;
        client.start(async);

        return 0;
    } catch (Exception &e)
    {
        cerr << e.what() << endl;
        _getch();
    }
    return -1;
}

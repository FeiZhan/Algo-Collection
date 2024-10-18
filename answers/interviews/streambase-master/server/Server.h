#include <tchar.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#include <State.h>
#include <Storage.h>

using namespace std;

class Server
{
private:
    static const int BUFFER_SIZE = 4096;
    static const int INSTANCES = 4;
    static const int PIPE_TIMEOUT = 5000;

    typedef struct
    {
        OVERLAPPED overlapped;
        HANDLE handle;
        TCHAR readBuffer[BUFFER_SIZE];
        DWORD readBytes;
        TCHAR writeBuffer[BUFFER_SIZE];
        DWORD writeBytes;
        State state;
        BOOL isPending;
    } Pipe;

    Pipe pipe[INSTANCES];

    Storage storage;

public:
    int start();

private:
    void reconnect(DWORD i);
    bool connect(HANDLE hPipe, LPOVERLAPPED lpo);
};

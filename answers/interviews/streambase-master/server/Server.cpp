#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#include <Constants.h>
#include <Exception.h>
#include <Helper.h>
#include <Server.h>

using namespace std;

int Server::start()
{
    LPTSTR lpszPipename = Helper::stringToLPTSTR(Constants::PIPE_NAME);
    DWORD i;
    HANDLE events[INSTANCES];
    for (i = 0; i < INSTANCES; i++)
    {
        events[i] = CreateEvent(
            NULL,
            TRUE,
            TRUE,
            NULL);
        if (events[i] == NULL)
        {
            throw Exception("CreateEvent failed. GLE = " + GetLastError());
        }
        pipe[i].overlapped.hEvent = events[i];
        pipe[i].handle = CreateNamedPipe(
            lpszPipename,
            PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
            PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
            INSTANCES,
            BUFFER_SIZE * sizeof(TCHAR),
            BUFFER_SIZE * sizeof(TCHAR),
            PIPE_TIMEOUT,
            NULL);
        if (pipe[i].handle == INVALID_HANDLE_VALUE)
        {
            throw Exception("CreateNamedPipe failed. GLE = " + GetLastError());
        }
        pipe[i].isPending = this->connect(pipe[i].handle, &pipe[i].overlapped);
        pipe[i].state = pipe[i].isPending ? CONNECTING_STATE : READING_STATE;
    }
    cout << "Server started." << endl;

    bool success;
    DWORD bytes;
    DWORD error;
    string output;
    while (1)
    {
        DWORD wait = WaitForMultipleObjects(
            INSTANCES,
            events,
            FALSE,
            INFINITE);
        i = wait - WAIT_OBJECT_0;
        if (i < 0 || i > (INSTANCES - 1))
        {
            throw Exception("Index out of range.");
        }

        if (pipe[i].isPending)
        {
            success = GetOverlappedResult(
                pipe[i].handle,
                &pipe[i].overlapped,
                &bytes,
                FALSE);
            switch (pipe[i].state)
            {
                case CONNECTING_STATE:
                    if (! success)
                    {
                        throw Exception("Error. GLE = " + GetLastError());
                    }
                    pipe[i].state = READING_STATE;
                    break;
                case READING_STATE:
                    if (! success || bytes == 0)
                    {
                        this->reconnect(i);
                        continue;
                    }
                    pipe[i].readBytes = bytes;
                    pipe[i].state = WRITING_STATE;
                    break;
                case WRITING_STATE:
                    if (! success || bytes != pipe[i].writeBytes)
                    {
                        this->reconnect(i);
                        continue;
                    }
                    pipe[i].state = READING_STATE;
                    break;
                default:
                    throw Exception("Invalid pipe state.");
            }
        }

        switch (pipe[i].state)
        {
            case READING_STATE:
                success = ReadFile(
                    pipe[i].handle,
                    pipe[i].readBuffer,
                    BUFFER_SIZE * sizeof(TCHAR),
                    &pipe[i].readBytes,
                    &pipe[i].overlapped);
                if (success && pipe[i].readBytes != 0)
                {
                    pipe[i].isPending = FALSE;
                    pipe[i].state = WRITING_STATE;
                    continue;
                }
                error = GetLastError();
                if (! success && (error == ERROR_IO_PENDING))
                {
                    pipe[i].isPending = TRUE;
                    continue;
                }
                this->reconnect(i);
                break;
            case WRITING_STATE:
                Sleep(1000);
                try
                {
                    output = this->storage.save(pipe[i].readBuffer);
                    cout << "Pipe#" << pipe[i].handle << ": " << output << endl;
                } catch (Exception &e)
                {
                    cerr << e.what() << endl;
                }

                StringCchCopy(pipe[i].writeBuffer, BUFFER_SIZE, output.c_str());
                pipe[i].writeBytes = (lstrlen(pipe[i].writeBuffer) + 1) * sizeof(TCHAR);
                success = WriteFile(
                    pipe[i].handle,
                    pipe[i].writeBuffer,
                    pipe[i].writeBytes,
                    &bytes,
                    &pipe[i].overlapped);
                if (success && bytes == pipe[i].writeBytes)
                {
                    pipe[i].isPending = FALSE;
                    pipe[i].state = READING_STATE;
                    continue;
                }
                error = GetLastError();
                if (! success && (error == ERROR_IO_PENDING))
                {
                    pipe[i].isPending = TRUE;
                    continue;
                }
                this->reconnect(i);
                break;
            default:
                throw Exception("Invalid pipe state.");
        }
    }

    return 0;
}

void Server::reconnect(DWORD i)
{
    if (! DisconnectNamedPipe(pipe[i].handle))
    {
        cout << "DisconnectNamedPipe failed with " << GetLastError() << endl;
    }
    pipe[i].isPending = this->connect(
        pipe[i].handle,
        &pipe[i].overlapped);
    pipe[i].state = pipe[i].isPending ?
        CONNECTING_STATE :
        READING_STATE;
}

bool Server::connect(HANDLE pipe, LPOVERLAPPED overlapped)
{
    bool connected = ConnectNamedPipe(pipe, overlapped);
    if (connected)
    {
        throw Exception("ConnectNamedPipe failed. GLE = " + GetLastError());
    }

    bool isPending = false;
    switch (GetLastError())
    {
        case ERROR_IO_PENDING:
            isPending = TRUE;
            break;
        case ERROR_PIPE_CONNECTED:
            if (SetEvent(overlapped->hEvent))
            {
                break;
            }
        default:
            throw Exception("ConnectNamedPipe failed. GLE = " + GetLastError());
    }
    return isPending;
}

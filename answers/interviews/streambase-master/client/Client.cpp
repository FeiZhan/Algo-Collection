#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <windows.h>

#include <Constants.h>
#include <Exception.h>
#include <Helper.h>
#include <Client.h>

using namespace std;

void Client::start(bool async) {
    if (async) {
        cout << "Using async" << endl;
    }
    while (true) {
        cout << "Type: ";
        string type;
        getline(cin, type);
        if (type.empty()) {
            break;
        }
        cout << "Value: ";
        string value;
        getline(cin, value);
        if (value.empty()) {
            break;
        }
        this->send(type + Constants::DELIMITER + value, async);
    }
}

int Client::send(string message, bool async)
{
    HANDLE pipe;
    LPTSTR pipeName = Helper::stringToLPTSTR(Constants::PIPE_NAME);
    while (1)
    {
        pipe = CreateFile(
            pipeName,
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            async ? FILE_FLAG_OVERLAPPED : 0,
            NULL);
        if (pipe != INVALID_HANDLE_VALUE)
        {
            break;
        }
        if (GetLastError() != ERROR_PIPE_BUSY)
        {
            throw Exception("Could not open pipe. GLE = " + GetLastError());
        }
        if (! WaitNamedPipe(pipeName, 20000))
        {
            throw Exception("Could not open pipe: 20 second wait timed out.");
        }
    }

    DWORD dwMode = PIPE_READMODE_MESSAGE;
    BOOL success = SetNamedPipeHandleState(
        pipe,
        &dwMode,
        NULL,
        NULL);
    if (! success)
    {
        throw Exception("SetNamedPipeHandleState failed. GLE = " + GetLastError());
    }

    LPTSTR lpvMessage = Helper::stringToLPTSTR(message);
    DWORD cbToWrite = (lstrlen(lpvMessage) + 1) * sizeof(TCHAR);
    DWORD cbWritten;
    OVERLAPPED overlapped;
    overlapped.hEvent = CreateEvent(
        NULL,
        TRUE,
        TRUE,
        NULL);
    cout << "Sending " << cbToWrite << " byte message: " << lpvMessage << endl;
    success = WriteFile(
        pipe,
        lpvMessage,
        cbToWrite,
        &cbWritten,
        &overlapped);
    if (! success)
    {
        throw Exception("WriteFile to pipe failed. GLE = " + GetLastError());
    }

    if (!async)
    {
        TCHAR chBuf[BUFFER_SIZE];
        DWORD cbRead;
        do
        {
            success = ReadFile(
                pipe,
                chBuf,
                BUFFER_SIZE * sizeof(TCHAR),
                &cbRead,
                &overlapped);
            if (! success && GetLastError() != ERROR_MORE_DATA) {
                break;
            }
            cout << "Replied message: " << chBuf << endl;
        } while (! success);
        if (! success)
        {
            throw Exception("ReadFile from pipe failed. GLE = " + GetLastError());
        }
    }

    CloseHandle(pipe);

    return 0;
}

#include <iostream>

using namespace std;

class Client
{
private:
    static const int BUFFER_SIZE = 512;

public:
    void start(bool async);

private:
    int send(string message, bool async);
};

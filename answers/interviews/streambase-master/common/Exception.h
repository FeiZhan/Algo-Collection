#include <iostream>

using namespace std;

class Exception : public exception
{
private:
    string message;

public:
    Exception(const char* message);
    Exception(string message);
    const char* what();
};

#include <iostream>

#include <Exception.h>

using namespace std;

Exception::Exception(const char* message)
{
    this->message = string(message);
}

Exception::Exception(string message)
{
    this->message = message;
}

const char* Exception::what()
{
    return this->message.c_str();
}

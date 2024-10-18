#include <iostream>

#include <Constants.h>
#include <Exception.h>
#include <Helper.h>
#include <Storage.h>

using namespace std;

HANDLE Storage::mutex = CreateMutex(
    NULL,
    FALSE,
    NULL);

Storage::Storage()
{
    this->count = 0;
}

string Storage::save(string input)
{
    while (true) {
        DWORD wait = WaitForSingleObject(
            mutex,
            INFINITE);
        if (wait == WAIT_OBJECT_0) {
            break;
        }
    }

    vector<string> tokens = Helper::split(input, Constants::DELIMITER);
    string output = tokens[1];
    if (tokens[0] == "integer")
    {
        this->valueStack.push(make_pair(TYPE_INTEGER, this->count));
        this->integers.insert(make_pair(this->count, stoi(tokens[1])));
        this->count++;
    }
    else if (tokens[0] == "float")
    {
        this->valueStack.push(make_pair(TYPE_FLOAT, this->count));
        this->floats.insert(make_pair(this->count, stod(tokens[1])));
        this->count++;
    }
    else if (tokens[0] == "complex")
    {
        if (tokens[1] == "toString" && this->complexes.size() > 0)
        {
            output = this->complexes.rbegin()->second.toString();
        }
        else if (tokens[1] == "getReal" && this->complexes.size() > 0)
        {
            output = to_string(this->complexes.rbegin()->second.getReal());
        }
        else if (tokens[1] == "getImaginary" && this->complexes.size() > 0)
        {
            output = to_string(this->complexes.rbegin()->second.getImaginary());
        }
        else if (tokens[1] == "abs" && this->complexes.size() > 0)
        {
            output = to_string(this->complexes.rbegin()->second.abs());
        }
        else
        {
            this->valueStack.push(make_pair(TYPE_COMPLEX, this->count));
            this->complexes.insert(make_pair(this->count, tokens[1]));
            this->count++;
        }
    }
    else if (tokens[0] == "string")
    {
        this->valueStack.push(make_pair(TYPE_STRING, this->count));
        this->strings.insert(make_pair(this->count, tokens[1]));
        this->count++;
    }
    else if (tokens[0] == "storage")
    {
        if (tokens[1] == "peek" && !this->valueStack.empty())
        {
            pair<Type, int> valuePair = this->valueStack.top();
            switch (valuePair.first)
            {
                case TYPE_INTEGER:
                    output = to_string(this->integers[valuePair.second]);
                    break;
                case TYPE_FLOAT:
                    output = to_string(this->floats[valuePair.second]);
                    break;
                case TYPE_COMPLEX:
                    output = this->complexes[valuePair.second].toString();
                    break;
                case TYPE_STRING:
                    output = this->strings[valuePair.second];
                    break;
            }
        }
    } else
    {
        throw Exception("Invalid input type: " + tokens[0]);
    }
    ReleaseMutex(mutex);
    return output;
}

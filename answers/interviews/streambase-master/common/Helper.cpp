#include <iostream>
#include <sstream>
#include <tchar.h>

#include <Helper.h>

using namespace std;

LPTSTR Helper::stringToLPTSTR(string str)
{
    LPTSTR lptstr = new TCHAR[str.size() + 1];
    strcpy(lptstr, str.c_str());
    return lptstr;
}

vector<string> Helper::split(string input, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(input);
    while (getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }
    return tokens;
}

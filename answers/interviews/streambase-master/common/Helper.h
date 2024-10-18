#include <iostream>
#include <vector>
#include <conio.h>
#include <tchar.h>
#include <windows.h>

using namespace std;

class Helper
{
public:
    static LPTSTR stringToLPTSTR(string str);
    static vector<string> split(string input, char delimiter);
};

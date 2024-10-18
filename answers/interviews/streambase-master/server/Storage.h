#include <iostream>
#include <stack>
#include <map>

#include <Type.h>
#include <Complex.h>

using namespace std;

class Storage
{
private:
    static HANDLE mutex;

    int count;
    map<int, int> integers;
    map<int, double> floats;
    map<int, Complex> complexes;
    map<int, string> strings;
    stack<pair<Type, int> > valueStack;

public:
    Storage();
    string save(string input);
};

//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <string>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	//cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int statements;
	cin >> statements;
	std::string state;
	int value = 0;
	for (int i = 0; i < statements; ++ i)
	{
		cin >> state;
		for (size_t i = 1; i < state.length(); ++ i)
		{
			if ('+' == state[i - 1] && '+' == state[i])
			{
				++ value;
			}
			if ('-' == state[i - 1] && '-' == state[i])
			{
				-- value;
			}
		}
	}
	std::cout << value << std::endl;
	return 0;
}

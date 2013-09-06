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
#include <vector>

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
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	std::string str;
	std::vector<std::vector<bool> > sym;
	for (int i = 0; i <= str.length(); ++ i)
	{
		sym.push_back(std::vector<bool> (str.length() + 1, false));
	}
	for (int i = 0; i <= str.length(); ++ i)
	{
		for (int j = 0; i + j <= str.length(); ++ j)
		{
			
		}
	}

	return 0;
}

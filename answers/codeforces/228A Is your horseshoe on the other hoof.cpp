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

#include <map>

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

	long long color;
	std::map<long long, int> colors;
	for (int i = 0; i < 4; ++ i)
	{
		std::cin >> color;
		if (0 == colors[color])
		{
			colors[color] = 1;
		} else
		{
			colors[color] ++;
		}
		if (colors.size() >= 4)
		{
			break;
		}
	}
	std::cout << ( (colors.size() >= 4) ? 0 : 4 - colors.size() ) << std::endl;

	return 0;
}

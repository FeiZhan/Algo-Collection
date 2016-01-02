// query table for each character to be removed

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

	std::string all, remove;
	std::getline(cin, all);
	std::getline(cin, remove);
	std::vector<bool> char_table(500, true);
	for (size_t i = 0; i < remove.length(); ++ i)
	{
		char_table[static_cast<unsigned>(remove[i])] = false;
	}
	for (size_t i = 0; i < all.length(); ++ i)
	{
		if (char_table[all[i]])
		{
			std::cout << all[i];
		}
	}
	std::cout << std::endl;

	return 0;
}

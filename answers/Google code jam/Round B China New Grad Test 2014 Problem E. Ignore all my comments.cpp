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

	std::string line;
	std::vector<std::string> prog;
	while (getline(std::cin, line))
	{
		prog.push_back(line);
	}
	int flag = 0, begin_prog = 0, begin_line = 0;
	for (size_t i = 0; i < prog.size(); ++ i)
	{
		for (size_t j = 0; j < prog[i].length(); ++ i)
		{
			if (prog[i][j] == '/')
			{
				if (flag == 0 && j + 1 < prog[i].length() && prog[i][j + 1] == '*')
				{
					flag = 1;
					begin_prog = i;
					begin_line = j;
				}
				else if (flag == 1 && j - 1 >= 0 && prog[i][j - 1] == '*')
				{
					flag = 0;
					prog.erase(prog.begin() + begin_prog, prog.begin() + i - 1);
					prog[j].erase(prog[j].begin() + begin_line, prog[j].begin() + j);
					i = begin_prog;
					j = begin_line;
				}
			}
		}
	}
	for (size_t i = 0; i < prog.size(); ++ i)
	{
		std::cout << prog[i] << std::endl;
	}

	return 0;
}

// undone
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

	std::string num;
	std::cin >> num;
	int ten = 10;
	std::vector<int> base;
	base.push_back(1);
	for (size_t i = 2; i < num.length(); ++ i)
	{
		base.push_back(base[base.size() - 1] * 9 + ten);
		ten *= 10;
	}
	for (size_t i = 0; i < base.size(); ++ i)
	{
		std::cout << base[i] << " ";
	}
	std::cout << std::endl;
	long long ones = 0;
	for (size_t i = 0; i < num.length() - 1; ++ i)
	{
		ones += (num[i] - 1) * base[num.length() - i - 1];
		if (num[i] > 1)
		{
			ones += 
		}
	}

	return 0;
}

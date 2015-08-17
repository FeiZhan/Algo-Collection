// Partly WA
// query table

#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

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

	int coin_num, money, coin;
	std::cin >> coin_num >> money;
	std::vector<int> coin_list(12000, 0);
	for (int i = 0; i < coin_num; ++ i)
	{
		std::cin >> coin;
		++ coin_list[coin];
	}
	bool flag = false;
	for (int i = 0; i < money / 2; ++ i)
	{
		if (coin_list[i] > 0 && coin_list[money - i] > 0)
		{
			std::cout << i << " " << money - i << std::endl;
			flag = true;
			break;
		}
	}
	if (0 == money % 2 && coin_list[money / 2] >= 2)
	{
		std::cout << money / 2 << " " << money / 2 << std::endl;
		flag = true;
	}
	if (! flag)
	{
		std::cout << "No Solution" << std::endl;
	}

	return 0;
}

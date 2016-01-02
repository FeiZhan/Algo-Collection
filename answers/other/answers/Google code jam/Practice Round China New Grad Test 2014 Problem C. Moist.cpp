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
#include <algorithm>

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

	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		int card_num;
		std::cin >> card_num;
		int money = 0;
		std::string card;
		std::vector<std::string> card_list;
		std::getline(std::cin, card);
		for (int j = 0; j < card_num; ++ j)
		{
			std::getline(std::cin, card);
			if (card_list.size() > 0 && card < card_list[card_list.size() - 1])
			{
				++ money;
			}
			card_list.push_back(card);
			std::sort(card_list.begin(), card_list.end());
		}
		std::cout << "Case #" << i + 1 << ": " << money << std::endl;
	}

	return 0;
}

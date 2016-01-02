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

	int cou_num, cou;
	std::cin >> cou_num;
	std::vector<int> cou_list;
	for (int i = 0; i < cou_num; ++ i)
	{
		std::cin >> cou;
		cou_list.push_back(cou);
	}
	std::sort(cou_list.begin(), cou_list.end());
	int pro_num, pro;
	std::cin >> pro_num;
	std::vector<int> pro_pos, pro_neg;
	for (int i = 0; i < pro_num; ++ i)
	{
		std::cin >> pro;
		if (pro >= 0)
		{
			pro_pos.push_back(pro);
		} else
		{
			pro_neg.push_back(pro);
		}
	}
	std::sort(pro_pos.begin(), pro_pos.end());
	std::sort(pro_neg.begin(), pro_neg.end());
	int income = 0;
	size_t cou_pos = cou_list.size() - 1;
	size_t cou_neg = 0;
	for (size_t i = 0; i < pro_pos.size(); ++ i)
	{
		if (cou_pos < 0 || cou_pos >= cou_list.size() || cou_list[cou_pos] < 0)
		{
			break;
		}
		income += cou_list[cou_pos] * pro_pos[pro_pos.size() - 1 - i];
		-- cou_pos;
	}
	for (size_t i = 0; i < pro_neg.size(); ++ i)
	{
		if (cou_pos < 0 || cou_pos >= cou_list.size() || cou_list[cou_neg] > 0)
		{
			break;
		}
		income += cou_list[cou_neg] * pro_neg[i];
		++ cou_neg;
	}
	std::cout << income << std::endl;

	return 0;
}

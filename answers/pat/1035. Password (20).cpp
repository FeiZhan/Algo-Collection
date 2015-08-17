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
#include <algorithm>
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

	int acc_num;
	std::cin >> acc_num;
	std::string name, pswd;
	std::string::iterator it;
	bool all_flag, flag;
	std::vector<std::string> names, pswds;
	for (int i = 0; i < acc_num; ++ i)
	{
		std::cin >> name >> pswd;
		all_flag = false;
		do
		{
			flag = false;
			it = std::find(pswd.begin(), pswd.end(), '1');
			if (pswd.end() != it)
			{
				flag = true;
				all_flag = true;
				*it = '@';
			}
			it = std::find(pswd.begin(), pswd.end(), '0');
			if (pswd.end() != it)
			{
				flag = true;
				all_flag = true;
				*it = '%';
			}
			it = std::find(pswd.begin(), pswd.end(), 'l');
			if (pswd.end() != it)
			{
				flag = true;
				all_flag = true;
				*it = 'L';
			}
			it = std::find(pswd.begin(), pswd.end(), 'O');
			if (pswd.end() != it)
			{
				flag = true;
				all_flag = true;
				*it = 'o';
			}
		} while (flag);
		if (all_flag)
		{
			names.push_back(name);
			pswds.push_back(pswd);
		}
	}
	if (0 == names.size())
	{
		std::cout << "There " << (acc_num > 1 ? "are" : "is") << " ";
		std::cout << acc_num << " account";
		std::cout << (acc_num > 1 ? "s" : "") << " and no account is modified" << std::endl;
	} else
	{
		std::cout << names.size() << std::endl;
		for (int i = 0; i < names.size(); ++ i)
		{
			std::cout << names[i] << " " << pswds[i] << std::endl;
		}
	}
	return 0;
}

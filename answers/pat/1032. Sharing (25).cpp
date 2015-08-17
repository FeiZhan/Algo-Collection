// TLE because of cin
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
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	std::string begin1, begin2;
	int add_num;
	std::cin >> begin1 >> begin2 >> add_num;
	std::map<std::string, char> char_map;
	std::map<std::string, std::string> add_map;
	std::string tmp1, tmp2;
	char tmp3;
	for (int i = 0; i < add_num; ++ i)
	{
		std::cin >> tmp1 >> tmp3 >> tmp2;
		char_map.insert(std::make_pair(tmp1, tmp3));
		add_map.insert(std::make_pair(tmp1, tmp2));
	}
	std::vector<std::string> add_vec1, add_vec2;
	add_vec1.push_back(begin1);
	while (true)
	{
		std::string &next( add_map[ add_vec1[add_vec1.size() - 1] ] );
		if ( "" == next || "-1" == next )
		{
			break;
		} else
		{
			add_vec1.push_back(next);
		}
	}
	add_vec2.push_back(begin2);
	while (true)
	{
		std::string &next( add_map[ add_vec2[add_vec2.size() - 1] ] );
		if ( "" == next || "-1" == next )
		{
			break;
		} else
		{
			add_vec2.push_back(next);
		}
	}
	std::string common("-1");
	for (int i = 0; i < add_vec1.size() && i < add_vec2.size(); ++ i)
	{
		if (add_vec1[add_vec1.size() - 1 - i] == add_vec2[add_vec2.size() - 1 - i])
		{
			common = add_vec1[add_vec1.size() - 1 - i];
		}
	}
	std::cout << common << std::endl;

	return 0;
}

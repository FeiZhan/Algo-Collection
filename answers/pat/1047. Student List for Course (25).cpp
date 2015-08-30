// partly WA, TLE
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
#include <set>
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

	int stu_num, cou_num;
	std::cin >> stu_num >> cou_num;
	int stu_cou_num, course;
	std::string name;
	std::vector<std::string> name_list;
	std::map<int, std::vector<int> > course_map;
	for (int i = 0; i < stu_num; ++ i)
	{
		std::cin >> name >> stu_cou_num;
		name_list.push_back(name);
		for (int j = 0; j < stu_cou_num; ++ j)
		{
			std::cin >> course;
			course_map[course].push_back(i);
		}
	}
	std::set<std::string> cou_name_list;
	for (std::map<int, std::vector<int> >::iterator it = course_map.begin(); it != course_map.end(); ++ it)
	{
		std::cout << it->first << " " << it->second.size() << std::endl;
		cou_name_list.clear();
		for (std::vector<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++ it2)
		{
			cou_name_list.insert(name_list[*it2]);
		}
		for (std::set<std::string>::iterator it2 = cou_name_list.begin(); it2 != cou_name_list.end(); ++ it2)
		{
			std::cout << *it2 << std::endl;
		}
	}

	return 0;
}

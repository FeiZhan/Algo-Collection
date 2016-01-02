// WA for large dataset
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
#include <map>
#include <set>
int name_hash(const std::string &name)
{
	int ans = 0;
	for (size_t i = 0; i < name.length(); ++ i)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
		{
			ans = ans * 26 + static_cast<int>(name[i] - 'A');
		} else
		{
			ans = ans * 26 + static_cast<int>(name[i] - '0');
		}
	}
	return ans;
}

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
	int hash_name;
	std::string name;
	std::multimap<int, int> cou_map;
	for (int i = 0; i < cou_num; ++ i)
	{
		int course, stu_list;
		//std::cin >> course >> stu_list;
		scanf("%d %d", &course, &stu_list);
		char tmp[6];
		for (int j = 0; j < stu_list; ++ j)
		{
			//std::cin >> name;
			scanf("%s", tmp);
			name = tmp;
			hash_name = name_hash(name);
			cou_map.insert(std::make_pair(hash_name, course));
		}
	}
	char tmp[6];
	for (int i = 0; i < stu_num; ++ i)
	{
		//std::cin >> name;
		scanf("%s", tmp);
		name = tmp;
		hash_name = name_hash(name);
		std::multimap<int, int>::iterator lower = cou_map.lower_bound(hash_name);
		std::set<int> cou_set;
		for (std::multimap<int, int>::iterator it = lower; it != cou_map.end() && it->first == hash_name; ++ it)
		{
			cou_set.insert(it->second);
		}
		std::cout << name << " " << cou_set.size();
		for (std::set<int>::iterator it = cou_set.begin(); it != cou_set.end(); ++ it)
		{
			std::cout << " " << *it;
		}
		std::cout << std::endl;
	}

	return 0;
}

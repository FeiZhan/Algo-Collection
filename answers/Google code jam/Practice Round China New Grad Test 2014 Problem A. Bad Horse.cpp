// validation of bipartite graph by BFS dyeing
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
#include <stack>
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
		int relation_num;
		std::cin >> relation_num;
		std::string name0, name1;
		std::map<std::string, int> color_map;
		std::multimap<std::string, std::string> relation_map;
		for (int j = 0; j < relation_num; ++ j)
		{
			std::cin >> name0 >> name1;
			relation_map.insert(std::make_pair(name0, name1));
			relation_map.insert(std::make_pair(name1, name0));
			color_map[name0] = 0;
			color_map[name1] = 0;
		}
		std::cout << "Case #" << i + 1 << ": ";
		if (color_map.size() < 2)
		{
			std::cout << "No" << std::endl;
			continue;
		}
		bool flag = false;
		std::string now;
		std::stack<std::string> relation_stack;
		relation_stack.push(color_map.begin()->first);
		color_map.begin()->second = 1;
		while (! relation_stack.empty())
		{
			now = relation_stack.top();
			relation_stack.pop();
			std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> range = relation_map.equal_range(now);
			for (std::multimap<std::string, std::string>::iterator it = range.first; it != range.second; ++ it)
			{
				if (color_map[it->second] == color_map[now])
				{
					flag = true;
					break;
				}
				if (color_map[it->second] == 0)
				{
					color_map[it->second] = - color_map[now];
					relation_stack.push(it->second);
				}
			}
			if (flag)
			{
				break;
			}
			if (relation_stack.empty())
			{
				for (std::map<std::string, int>::iterator it = color_map.begin(); it != color_map.end(); ++ it)
				{
					if (0 == it->second)
					{
						relation_stack.push(it->first);
					}
				}
			}
		}
		std::cout << (flag ? "No" : "Yes") << std::endl;
	}

	return 0;
}

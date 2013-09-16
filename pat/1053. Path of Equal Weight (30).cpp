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
#include <map>
#include <algorithm>
std::vector<int> node_list;
bool compare(int x, int y)
{
	return node_list[x] > node_list[y];
}
void dfs(const int now, const int sum, const std::vector<int> &node_list, std::map<int, vector<int> > &node_map, const std::vector<int> &path)
{
	if ( node_list[now] > sum)
	{
		return;
	}
	if ( node_list[now] == sum && node_map[now].size() == 0)
	{
		for (size_t i = 0; i < path.size(); ++ i)
		{
			std::cout << path[i] << " ";
		}
		std::cout << node_list[now] << std::endl;
		return;
	}
	std::vector<int> p(path);
	p.push_back(node_list[now]);
	for (size_t i = 0; i < node_map[now].size(); ++ i)
	{
		dfs(node_map[now][i], sum - node_list[now], node_list, node_map, p);
	}
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

	int node_num, nonleaf_num, sum;
	std::cin >> node_num >> nonleaf_num >> sum;
	for (int i = 0; i < node_num; ++ i)
	{
		int node;
		std::cin >> node;
		node_list.push_back(node);
	}
	std::map<int, vector<int> > node_map;
	for (int i = 0; i < nonleaf_num; ++ i)
	{
		int node, child_num;
		std::cin >> node >> child_num;
		int child;
		std::vector<int> child_list;
		for (int j = 0; j < child_num; ++ j)
		{
			std::cin >> child;
			child_list.push_back(child);
		}
		std::sort(child_list.begin(), child_list.end(), compare);
		node_map.insert(std::make_pair(node, child_list));
	}
	std::vector<int> path;
	dfs(0, sum, node_list, node_map, path);

	return 0;
}

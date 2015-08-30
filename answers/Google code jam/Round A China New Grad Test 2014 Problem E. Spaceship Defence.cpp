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
#include <climits>
void dfs(const int from, const int to, int now_time, int &min_time, const std::vector<std::vector<int> > &time_map, std::vector<bool> &visited)
{
	if (from >= time_map.size() || to >= time_map.size() || now_time > min_time)
	{
		return;
	}
	if (from == to)
	{
		if (min_time > now_time)
		{
			min_time = now_time;
		}
		return;
	}
	visited[from] = true;
	for (size_t i = 0; i < time_map[from].size(); ++ i)
	{
		if (i != from && ! visited[i] && time_map[from][i] < INT_MAX && now_time + time_map[from][i] < min_time)
		{
			visited[i] = true;
			dfs(i, to, now_time + time_map[from][i], min_time, time_map, visited);
			visited[i] = false;
		}
	}
}
void dij(std::vector<std::vector<int> > &time_map)
{
	std::vector<int> visited(time_map.size(), false);
	visited[0] = true;
	for (int i = 0; i < time_map.size(); ++ i)
	{
		int min_dist = INT_MAX;
		for (int j = 0; j < visited.size(); ++ j)
		{
			if (! visited[j])
			{
				continue;
			}
			for (int k = 0; k < time_map.size(); ++ k)
			{
				if (! visited[k] && )
			}
		}
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

	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		int room_num;
		std::cin >> room_num;
		std::vector<std::vector<int> > time_map(room_num, std::vector<int>(room_num, INT_MAX));
		std::string color;
		std::vector<std::string> color_list;
		for (int j = 0; j < room_num; ++ j)
		{
			std::cin >> color;
			color_list.push_back(color);
			for (size_t k = 0; k < color_list.size(); ++ k)
			{
				if (color_list[k] == color)
				{
					time_map[color_list.size() - 1][k] = time_map[k][color_list.size() - 1] = 0;
				}
			}
		}
		int lift_num;
		std::cin >> lift_num;
		std::vector<int> lift_from_list, lift_to_list, lift_time_list;
		for (int j = 0; j < lift_num; ++ j)
		{
			int from, to, time;
			std::cin >> from >> to >> time;
			-- from;
			-- to;
			lift_from_list.push_back(from);
			lift_from_list.push_back(to);
			lift_from_list.push_back(time);
			if (time_map[from][to] > time)
			{
				time_map[from][to] = time;
			}
			for (int k = 0; k < room_num; ++ k)
			{
				if (time_map[to][k] < INT_MAX && time_map[from][k] > time_map[from][to] + time_map[to][k])
				{
					time_map[from][k] = time_map[from][to] + time_map[to][k];
				}
			}
		}
		int sol_num;
		std::cin >> sol_num;
		std::cout << "Case #" << i + 1 << ":" << std::endl;
		for (int j = 0; j < sol_num; ++ j)
		{
			int from, to;
			std::cin >> from >> to;
			int min_time = INT_MAX;
			if (from == to)
			{
				min_time = 0;
			}
			std::vector<bool> visited(room_num, false);
			visited[from - 1] = true;
			dfs(from - 1, to - 1, 0, min_time, time_map, visited);
			std::cout << (INT_MAX == min_time ? -1 : min_time) << std::endl;
		}
	}

	return 0;
}

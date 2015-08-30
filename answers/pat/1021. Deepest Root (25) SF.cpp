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
#include <set>
#include <climits>

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

	int node_num, begin, end;
	std::cin >> node_num;
	std::vector<std::vector<int> > dist;
	for (int i = 0; i < node_num; ++ i)
	{
		dist.push_back(std::vector<int> (node_num, INT_MAX));
	}
	for (int i = 0; i < node_num; ++ i)
	{
		std::cin >> begin >> end;
		-- begin;
		-- end;
		dist[begin][end] = 1;
		dist[end][begin] = 1;
		for (int j = 0; j < node_num; ++ j)
		{
			if (dist[j][begin] < INT_MAX && dist[j][end] < INT_MAX)
			{
				if (dist[j][begin] > dist[j][end] + 1)
				{
					dist[j][begin] = dist[j][end] + 1;
					dist[begin][j] = dist[j][end] + 1;
				}
				if (dist[j][end] > dist[j][begin] + 1)
				{
					dist[j][end] = dist[j][begin] + 1;
					dist[end][j] = dist[j][begin] + 1;
				}
			}
		}
	}
	int max_dist = 0;
	std::set<int> aaa;
	aaa.insert(1);
	//segmentation fault
	for (int i = 0; i < node_num; ++ i)
	{
		for (int j = 0; j < node_num; ++ j)
		{
			//if (dist[i][j] < INT_MAX && dist[i][j] > max_dist)
			//{
				//max_dist = dist[i][j];
				//deepest.clear();
				//deepest.insert(i);
				//deepest.insert(j);
			//}// else if (dist[i][j] == max_dist)
			//{
				//deepest.insert(i);
				//deepest.insert(j);
			//}
		}
	}
/*
	for (std::set<int>::iterator it = deepest.begin(); it != deepest.end(); ++ it)
	{
		std::cout << (*it) + 1 << std::endl;
	}
*/
	return 0;
}

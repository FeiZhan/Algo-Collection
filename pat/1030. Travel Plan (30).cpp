// SF
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
struct Node
{
	int dist, cost, path;
	Node() : dist(INT_MAX), cost(INT_MAX), path(-1)
	{}
};
struct Edge
{
	int end, dist, cost;
	Edge(int e, int d, int c) : end(e), dist(d), cost(c)
	{}
};
//int n, m, s, t;
int city_num, high_num, start, dest;
std::vector<std::vector<Edge> > edge;
std::vector<int> path;
std::vector<Node> city;
std::vector<bool> visited;
int findMin()
{
	int mmin = INT_MAX;
	int k = -1;
	for (int i = 0; i < city_num; ++ i)
	{
		if (! visited[i] && city[i].dist < mmin)
		{
			mmin = city[i].dist;
			k = i;
		}
	}
	return k;
}
void Dijkstra(int start, int dest)
{
	visited.assign(city_num, false);
	city.clear();
	city.resize(city_num);
	city[start].dist = 0;
	city[start].cost = 0;
	while (true)
	{
		int u = findMin();
		if (-1 == u)
		{
			return;
		}
		visited[u] = true;
		for (int i = 0; i < edge[u].size(); ++ i)
		{
			int v = edge[u][i].end;
			int cost = edge[u][i].cost;
			int dist = edge[u][i].dist;
			if (! visited[v])
			{
				if (city[v].dist > city[u].dist + dist)
				{
					city[v].dist = city[u].dist + dist;
					city[v].cost = city[u].cost + cost;
					city[v].path = u;
				}
				else if (city[v].dist == city[u].dist + dist && city[v].cost > city[u].cost + cost)
				{
					city[v].cost = city[u].cost + cost;
					city[v].path = u;
				}
			}
		}
	}
}
void outputPath(int t)
{
	std::stack<int> ans;
	ans.push(t);
	while (-1 != city[t].path)
	{
		t = city[t].path;
		ans.push(t);
	}
	while (! ans.empty())
	{
		std::cout << ans.top() << " ";
		ans.pop();
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

	while (std::cin >> city_num >> high_num >> start >> dest)
	{
		edge.clear();
		edge.resize(city_num);
		while (-- high_num)
		{
			int u, v, d, c;
			//std::cin >> u >> v >> d >> c;
			//edge[u].push_back(Edge(v, d, c));
			//edge[v].push_back(Edge(u, d, c));
		}
		//Dijkstra(start, dest);
		//outputPath(dest);
		//std::cout << city[dest].dist << " " << city[dest].cost << std::endl;
	}

	return 0;
}

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

#include <climits>
#include <string>
#include <vector>
#include <stack>

struct Highway {
	int from, to, dist, cost;
	Highway(int f, int t, int d, int c) : from(f), to(t), dist(d), cost(c)
	{}
};
int city_num, high_num, start, target;

void dfs(int current, vector<int> &path, int dist, int cost, const vector<int> &prev_list, const vector<vector<Highway> > &city_list) {
	path.insert(path.begin(), current);
	if (start == current) {
		for (size_t i = 0; i < path.size(); ++ i) {
			cout << path[i] << " ";
		}
		cout << dist << " " << cost << endl;
		return;
	}
	int prev = prev_list[current];
	for (size_t j = 0; j < city_list[prev].size(); ++ j) {
		if (city_list[prev][j].to == current) {
			dfs(prev, path, dist + city_list[prev][j].dist, cost + city_list[prev][j].cost, prev_list, city_list);
		}
	}
}

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

	cin >> city_num >> high_num >> start >> target;
	vector<vector<Highway> > city_list(city_num);
	for (int i = 0; i < high_num; ++ i) {
		int from, to, dist, cost;
		cin >> from >> to >> dist >> cost;
		city_list[from].push_back(Highway(from, to, dist, cost));
		city_list[to].push_back(Highway(to, from, dist, cost));
	}
	vector<int> dist_list(city_num, INT_MAX);
	vector<int> cost_list(city_num, INT_MAX);
	vector<int> prev_list(city_num, INT_MAX);
	stack<int> city_stack;
	city_stack.push(start);
	dist_list[start] = 0;
	while (! city_stack.empty()) {
		int current = city_stack.top();
		city_stack.pop();
		for (size_t i = 0; i < city_list[current].size(); ++ i) {
			int next = city_list[current][i].to;
			if (dist_list[next] > dist_list[current] + city_list[current][i].dist || (dist_list[next] == dist_list[current] + city_list[current][i].dist && cost_list[next] > cost_list[current] + city_list[current][i].cost)) {
				dist_list[next] = dist_list[current] + city_list[current][i].dist;
				cost_list[next] = cost_list[current] + city_list[current][i].cost;
				prev_list[next] = current;
				city_stack.push(next);
			}
		}
	}
	vector<int> path;
	dfs(target, path, 0, 0, prev_list, city_list);

	return 0;
}




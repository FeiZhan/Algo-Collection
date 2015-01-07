// WA
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
#include <vector>
#include <queue>

size_t city_num, road_num, start, target;
vector<int> team_list;
vector<vector<int> > city_mat;
vector<size_t> dist;
vector<vector<size_t> > previous;
vector<bool> visit;

int dfs(size_t start, size_t end, int &team_max) {
	if (start == end) {
		team_max = std::max(team_max, team_list[end]);
		return 1;
	}
	visit[end] = true;
	int path_count = 0;
	for (size_t i = 0; i < previous[end].size(); ++i) {
		if (visit[previous[end][i]]) {
			continue;
		}
		int team = 0;
		int path = dfs(start, previous[end][i], team);
		path_count += path;
		team_max = std::max(team_max, team + team_list[end]);
	}
	visit[end] = false;
	return path_count;
}
void dijkstra(void) {
	queue<size_t> city_que;
	city_que.push(start);
	dist[start] = 0;
	while (!city_que.empty()) {
		size_t current = city_que.front();
		city_que.pop();
		for (size_t i = 0; i < city_mat[current].size(); ++i) {
			if (INT_MAX == city_mat[current][i]) {
				continue;
			}
			if (dist[current] + city_mat[current][i] < dist[i]) {
				dist[i] = dist[current] + city_mat[current][i];
				previous[i].clear();
				previous[i].push_back(current);
				city_que.push(i);
			}
			else if (dist[current] + city_mat[current][i] == dist[i]) {
				previous[i].push_back(current);
				city_que.push(i);
			}
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

	cin >> city_num >> road_num >> start >> target;
	for (size_t i = 0; i < city_num; ++i) {
		size_t team_num;
		cin >> team_num;
		team_list.push_back(team_num);
	}
	city_mat.assign(city_num, vector<int>(city_num, INT_MAX));
	for (size_t i = 0; i < road_num; ++i) {
		size_t begin, end, len;
		cin >> begin >> end >> len;
		city_mat[begin][end] = len;
		city_mat[end][begin] = len;
	}
	dist.assign(city_num, INT_MAX);
	previous.resize(city_num);
	visit.assign(city_num, false);
	dijkstra();

	/*cout << city_num << " " << road_num << " " << start << " " << target << endl << "team_list ";
	for (size_t i = 0; i < team_list.size(); ++i) {
		cout << team_list[i] << " ";
	}
	cout << endl << "city_mat ";
	for (size_t i = 0; i < city_mat.size(); ++i) {
		for (size_t j = 0; j < city_mat[i].size(); ++j) {
			cout << city_mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "dist ";
	for (size_t i = 0; i < dist.size(); ++i) {
		cout << dist[i] << " ";
	}
	cout << endl << "previous ";
	for (size_t i = 0; i < previous.size(); ++i) {
		for (size_t j = 0; j < previous[i].size(); ++j) {
			cout << previous[i][j] << " ";
		}
		cout << endl;
	}*/

	int team_max = 0;
	visit.assign(city_num, false);
	int path_count = dfs(start, target, team_max);
	cout << path_count << " " << team_max << endl;

	return 0;
}




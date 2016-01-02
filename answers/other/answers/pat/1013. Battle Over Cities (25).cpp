//
#include <iostream>
using namespace std;

#include <vector>

void dfs(size_t current, vector<bool> &visit_flag, const vector<vector<bool> > &highway_map) {
	visit_flag[current] = true;
	for (size_t i = 0; i < highway_map.size(); ++ i) {
		if (! visit_flag[i] && highway_map[current][i]) {
			dfs(i, visit_flag, highway_map);
		}
	}
}
int main (int argc, char *argv[])
{
	size_t city_num(0), highway_num(0), check_num(0);
	while (cin >> city_num >> highway_num >> check_num) {
		vector<vector<bool> > highway_map(city_num, vector<bool> (city_num, false));
		for (size_t i = 0; i < highway_num; ++ i) {
			size_t start(0), end(0);
			cin >> start >> end;
			-- start;
			-- end;
			highway_map[start][end] = true;
			highway_map[end][start] = true;
		}
		size_t check(0);
		vector<bool> remove_list(city_num, false);
		for (size_t i = 0; i < check_num; ++ i) {
			for (size_t i = 0; i < remove_list.size(); ++ i) {
				if (remove_list[i]) {
					highway_map[check][i] = true;
					highway_map[i][check] = true;
				}
			}
			cin >> check;
			-- check;
			for (size_t i = 0; i < highway_map.size(); ++ i) {
				remove_list[i] = highway_map[check][i];
				highway_map[check][i] = false;
				highway_map[i][check] = false;
			}
			vector<bool> visit_flag(city_num, false);
			size_t count(0);
			for (size_t i = 0; i < city_num; ++ i) {
				if (i != check && ! visit_flag[i]) {
					++ count;
					dfs(i, visit_flag, highway_map);
				}
			}
			cout << count - 1 << endl;
		}
	}

	return 0;
}
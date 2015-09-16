//@type dfs, graph
//@result 12965277	2015-09-11 23:24:21	zetta217	217A - Ice Skating	GNU C++	Accepted	62 ms	0 KB
#include <iostream>
using namespace std;
#include <vector>
#include <utility>

void dfs(size_t current, const vector<pair<int, int> > &snow_list, vector<bool> &visit_list) {
	if (current >= visit_list.size() || visit_list[current]) {
		return;
	}
	visit_list[current] = true;
	for (size_t i = 0; i < snow_list.size(); ++ i) {
		if (! visit_list[i] && (snow_list[i].first == snow_list[current].first || snow_list[i].second == snow_list[current].second)) {
			dfs(i, snow_list, visit_list);
		}
	}
}
int main() {
	int snow_num(0);
	while (cin >> snow_num) {
		vector<pair<int, int> > snow_list;
		for (int i = 0; i < snow_num; ++ i) {
			int x(0);
			int y(0);
			cin >> x >> y;
			snow_list.push_back(make_pair(x, y));
		}
		vector<bool> visit_list(snow_list.size(), false);
		int count(0);
		for (size_t i = 0; i < snow_list.size(); ++ i) {
			if (! visit_list[i]) {
				dfs(i, snow_list, visit_list);
				++ count;
			}
		}
		cout << count - 1 << endl;
	}
	return 0;
}
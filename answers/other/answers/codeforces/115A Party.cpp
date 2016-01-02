//@type dfs, tree
//@result 12964347	2015-09-11 21:43:14	zetta217	115A - Party	GNU C++	Accepted	62 ms	0 KB
#include <iostream>
using namespace std;
#include <vector>

int dfs(size_t current, const vector<int> &employee_list, vector<bool> &visit_list) {
	if (current >= visit_list.size() || visit_list[current]) {
		return 0;
	}
	visit_list[current] = true;
	int depth(0);
	if (employee_list[current] < 0) {
		depth = 1;
	}
	else {
		depth = dfs(employee_list[current], employee_list, visit_list) + 1;
	}
	//cout << "test " << current << "->" << employee_list[current] << ": " << depth << endl;
	return depth;
}
int main() {
	int employee_num(0);
	while (cin >> employee_num) {
		vector<int> employee_list;
		for (int i = 0; i < employee_num; ++ i) {
			int employee(0);
			cin >> employee;
			employee_list.push_back(employee - 1);
		}
		int depth_max(0);
		for (size_t i = 0; i < employee_list.size(); ++ i) {
			vector<bool> visit_list(employee_num, false);
			int depth = dfs(i, employee_list, visit_list);
			if (depth > depth_max) {
				depth_max = depth;
			}
		}
		cout << depth_max << endl;
	}
	return 0;
}
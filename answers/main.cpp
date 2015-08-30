#include <iostream>
using namespace std;
#include <vector>

int dfs(int x, int order, vector<vector<int> > &dp, vector<vector<bool> > &visit_flag, const vector<int> &int_list) {
	if (x < 0 || x >= dp.size()) {
		return 0;
	}
	if (visit_flag[x][order]) {
		return -1;
	}
	visit_flag[x][order] = true;
	int result(0);
	switch (order) {
	case 0:
		result = dfs(x + int_list[x], 1, dp, visit_flag, int_list);
		break;
	case 1:
		result = dfs(x - int_list[x], 0, dp, visit_flag, int_list);
		break;
	}
	if (-1 == result) {
		return -1;
	}
	else {
		dp[x][order] += result + int_list[x];
		return dp[x][order];
	}
}
int main() {
	int int_num(0);
	while (cin >> int_num) {
		-- int_num;
		vector<int> int_list;
		for (int i = 0; i < int_num; ++ i) {
			int integer(0);
			cin >> integer;
			int_list.push_back(integer);
		}
		vector<vector<int> > dp(int_list.size(), vector<int> (2, 0));
		vector<vector<bool> > visit_flag(int_list.size(), vector<bool> (2, false));
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				dfs(i, j, dp, visit_flag, int_list);
			}
		}
		for (size_t i = 0; i < dp.size(); ++ i) {
			cout << dp[i][0] << " " << dp[i][1] << endl;
		}
		cout << endl;
	}
	return 0;
}
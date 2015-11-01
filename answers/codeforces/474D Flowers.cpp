//@type DP
//@result 12878839	2015-09-07 04:42:10	zetta217	474D - Flowers	GNU C++	Accepted	623 ms	3900 KB
#include <iostream>
using namespace std;
#include <climits>
#include <vector>

int main() {
	const int MOD = 1e9+7;
	const int MAXN = 5e5 + 5;
	int case_num(0);
	int group(0);
	while (cin >> case_num >> group) {
		vector<int> way_list(MAXN, 0);
		vector<int> acc_list(MAXN, 0);
		way_list[0] = 1;
		acc_list[0] = way_list[0];
		way_list[1] = 1;
		acc_list[1] = acc_list[0] + way_list[1];
		for (size_t i = 1; i < way_list.size(); ++ i) {
			way_list[i] = way_list[i - 1];
			if (i >= group) {
				way_list[i] = (way_list[i] + way_list[i - group]) % MOD;
			}
			// accumulate to speed up
			acc_list[i] = (way_list[i] + acc_list[i - 1]) % MOD;
			if (i < 10) {
				//cout << "test " << i << " " << way_list[i] << " " << acc_list[i] << endl;
			}
		}
		for (int i = 0; i < case_num; ++ i) {
			int a(0), b(0);
			cin >> a >> b;
			int sum(0);
			int max_flower(min(max(a, b), int(way_list.size()) - 1));
			int min_flower(max(min(a, b), 1));
			cout << (acc_list[max_flower] - acc_list[min_flower - 1] + MOD) % MOD << endl;
		}
	}
	return 0;
}
//@type DP, two pointers
//@result 12876974	2015-09-06 23:02:09	zetta217	363B - Fence	GNU C++	Accepted	234 ms	2100 KB
#include <iostream>
using namespace std;
#include <climits>
#include <vector>

int main() {
	int plank_num(0);
	int piano(0);
	while (cin >> plank_num >> piano) {
		vector<int> plank_list;
		int sum(0);
		int min_sum(INT_MAX);
		int min_index(0);
		for (int i = 0; i < plank_num; ++ i) {
			int plank(0);
			cin >> plank;
			plank_list.push_back(plank);
			sum += plank;
			if (i + 1 >= piano) {
				if (i >= piano) {
					sum -= plank_list[i - piano];
				}
				//cout << "test " << i << " " << sum << endl;
				if (sum < min_sum) {
					min_sum = sum;
					min_index = i - piano + 1;
				}
			}
		}
		cout << min_index + 1 << endl;
	}
	return 0;
}
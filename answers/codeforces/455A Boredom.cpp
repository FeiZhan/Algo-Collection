//@type DP
//@result 12875328	2015-09-06 20:04:12	zetta217	455A - Boredom	GNU C++	Accepted	249 ms	3300 KB
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

int main() {
	long long int_num(0);
	while (cin >> int_num) {
		map<long long, long long> int_map;
		for (long long i = 0; i < int_num; ++ i) {
			long long integer(0);
			cin >> integer;
			if (int_map.end() == int_map.find(integer)) {
				int_map.insert(make_pair(integer, 0));
			}
			++ int_map[integer];
		}
		vector<long long> point_list(int_map.rbegin()->first + 1, 0);
		if (int_map.end() != int_map.find(1)) {
			point_list[1] = 1 * int_map[1];
		}
		for (long long i = 2; i < point_list.size(); ++ i) {
			// DP equation: dp[i] = max{dp[i - 1], dp[i - 2] + i * map[i]}, dp[i] is the max between 1 - i
			point_list[i] = point_list[i - 1];
			if (int_map.end() != int_map.find(i)) {
				point_list[i] = max(point_list[i], point_list[i - 2] + i * int_map[i]);
			}
			//cout << "test " << i << " " << point_list[i] << endl;
		}
		cout << max(point_list[point_list.size() - 1], point_list[point_list.size() - 2]) << endl;
	}
	return 0;
}
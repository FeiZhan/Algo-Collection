//@type combinatorics, dp
//@result 12796143	2015-09-01 05:02:00	zetta217	414B - Mashmokh and ACM	GNU C++	Accepted	78 ms	16600 KB
#include <iostream>
using namespace std;
#include <vector>

int main() {
	int max(0);
	int length(0);
	while (cin >> max >> length) {
		// dp[i][j]: the number of combinations with length i and the maximum number j
		vector<vector<int> > dp(length, vector<int> (max + 1, 0));
		for (size_t i = 1; i < dp[0].size(); ++ i) {
			dp[0][i] = 1;
		}
		for (size_t i = 1; i < dp.size(); ++ i) {
			for (size_t j = 1; j < dp[i].size(); ++ j) {
				for (size_t k = 1; j * k < dp[i].size(); ++ k) {
					//cout << "test " << i << " " << j << " " << k << endl;
					dp[i][j * k] = (dp[i][j * k] + dp[i - 1][j]) % 1000000007;
				}
			}
		}
		int sum(0);
		for (size_t i = 0; i < dp[length - 1].size(); ++ i) {
			//cout << "test " << i << " " << dp[length - 1][i] << endl;
			sum = (sum + dp[length - 1][i]) % 1000000007;
		}
		cout << sum << endl;
	}
	return 0;
}
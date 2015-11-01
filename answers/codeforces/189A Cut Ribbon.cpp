//@type dp
//@result 12876704	2015-09-06 22:29:00	zetta217	189A - Cut Ribbon	GNU C++	Accepted	31 ms	0 KB
#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <algorithm>

int main() {
	int ribbon(0);
	while (cin >> ribbon) {
		vector<int> piece_list;
		vector<int> dp(ribbon + 1, INT_MIN);
		for (size_t i = 0; i < 3; ++ i) {
			int piece(0);
			cin >> piece;
			piece_list.push_back(piece);
			if (piece <= ribbon) {
				dp[piece] = 1;
			}
		}
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < piece_list.size(); ++ j) {
				if (i >= piece_list[j]) {
					dp[i] = max(dp[i], dp[i - piece_list[j]] + 1);
				}
			}
			//cout << "test " << i << " " << dp[i] << endl;
		}
		cout << dp[ribbon] << endl;
	}
	return 0;
}
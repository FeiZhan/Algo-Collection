//
#include <cstdio>
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

int main (int argc, char *argv[])
{
	int coin_num(0);
	int pay(0);
	while (cin >> coin_num >> pay) {
		vector<int> coin_list;
		for (int i = 0; i < coin_num; ++ i) {
			int coin(0);
			cin >> coin;
			coin_list.push_back(coin);
		}
		// greater
		sort(coin_list.begin(), coin_list.end(), std::greater<int>());
		vector<vector<int> > dp(coin_list.size(), vector<int> (pay + 1, 0));
		vector<vector<bool> > take_list(coin_list.size(), vector<bool> (pay + 1, false));
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 1; j < dp[i].size(); ++ j) {
				if (0 == i) {
					if (j < coin_list[i]) {
						dp[i][j] = 0;
					}
					else {
						dp[i][j] = coin_list[i];
						take_list[i][j] = true;
					}
				}
				else if (j < coin_list[i] || dp[i - 1][j] > dp[i - 1][j - coin_list[i]] + coin_list[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - coin_list[i]] + coin_list[i];
					take_list[i][j] = true;
				}
			}
		}
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				//if (take_list[i][j])
					//cout << "dp " << i << " " << j << " " << dp[i][j] << " " << take_list[i][j] << endl;
			}
		}
		if (dp[coin_list.size() - 1][pay] != pay) {
			cout << "No Solution" << endl;
		}
		else {
			int money(pay);
			bool first_flag(true);
			for (size_t i = coin_list.size() - 1; i < coin_list.size() && money >= 0; -- i) {
				if (take_list[i][money]) {
					money -= coin_list[i];
					if (first_flag) {
						first_flag = false;
					}
					else {
						cout << " ";
					}
					cout << coin_list[i];
				}
			}
			cout << endl;
		}
	}

	return 0;
}
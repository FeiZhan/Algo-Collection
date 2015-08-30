class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<vector<bool> > dp(s.length(), vector<bool> (s.length(), false));
		for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++ it) {
			size_t pos = 0;
			while (pos + it->length() <= s.length()) {
				size_t new_pos = s.find(*it, pos);
				if (std::string::npos == new_pos) {
					break;
				}
				dp[new_pos][new_pos + it->length() - 1] = true;
				pos = new_pos + 1;
			}
		}
		for (size_t i = 0; i < s.length(); ++ i) {
			for (size_t j = i + 1; j < s.length(); ++ j) {
				if (dp[i][j]) {
					continue;
				}
				for (size_t k = i; k < j; ++ k) {
					if (dp[i][k] && dp[k + 1][j]) {
						dp[i][j] = true;
						break;
					}
				}
			}
		}
		//printDp(dp);
		return dp[0][s.length() - 1];
	}
	void printDp(const vector<vector<bool> > &dp) {
		cout << "dp ";
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	}
};

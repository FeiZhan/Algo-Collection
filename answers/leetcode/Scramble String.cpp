
class Solution {
public:
	bool isScramble(string s1, string s2) {
		vector<vector<vector<bool> > > dp(s1.size(), vector<vector<bool> > (s1.size(), vector<bool> (s1.size(), false)));
		for (size_t i = 0; i < s1.size() && i < s2.size(); ++ i) {
			for (size_t j = 0; i + j < s1.size() && i + j < s2.size(); ++ j) {
				for (size_t k = 0; i + k < s1.size() && i + k < s2.size(); ++ k) {
					if (s1.substr(j, i + 1) == s2.substr(k, i + 1)) {
						dp[i][j][k] = true;
						continue;
					}
					for (size_t m = 0; m < i; ++ m) {
						if ((dp[m][j][k] && dp[i - m - 1][j + m + 1][k + m + 1]) || (dp[m][j][k + i - m] && dp[i - m - 1][j + m + 1][k])) {
							dp[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
		return dp[s1.size() - 1][0][0];
	}
};

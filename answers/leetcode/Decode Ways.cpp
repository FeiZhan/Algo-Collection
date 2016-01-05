// 2014-12-24
//@result 259 / 259 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 13.04% of cpp submissions.

class Solution {
public:
	int numDecodings(string s) {
		if (0 == s.length()) {
			return 0;
		}
		std::vector<int> dp(s.length(), 0);
		dp[0] = s[0] > '0';
		for (size_t i = 1; i < s.length(); ++ i) {
			if ((s[i - 1] == '1' && s[i] > '0') || ('2' == s[i - 1] && s[i] > '0' && s[i] <= '6')) {
				if (i >= 2) {
					dp[i] = dp[i - 2] + dp[i - 1];
				} else {
					dp[i] = dp[i - 1] + 1;
				}
			}
			else if ('0' == s[i]) {
				if (s[i - 1] >= '1' && s[i - 1] <= '2') {
					if (i >= 2) {
						dp[i] = dp[i - 2];
					} else {
						dp[i] = 1;
					}
				} else {
					dp[i] = 0;
				}
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		return dp[s.length() - 1];
	}
};

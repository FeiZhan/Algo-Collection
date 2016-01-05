// 2014-12-14
//@result 101 / 101 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 7.65% of cpp submissions.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) {
			return false;
		}
		if (0 == s1.length()) {
			return s2 == s3;
		}
		if (0 == s2.length()) {
			return s1 == s3;
		}
		std::vector<std::vector<bool> > dp(s1.length() + 1, std::vector<bool> (s2.length() + 1, false));
		dp[0][0] = true;
		for (size_t i = 1; i <= s1.length(); ++ i) {
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		}
		for (size_t i = 1; i <= s2.length(); ++ i) {
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
		}
		for (size_t i = 1; i <= s1.length(); ++ i) {
			for (size_t j = 1; j <= s2.length(); ++ j) {
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[s1.length()][s2.length()];
    }
};

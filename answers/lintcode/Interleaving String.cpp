//@result 

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
		if (s1.length() + s2.length() != s3.length()) {
			return false;
		}
		vector<vector<bool> > dp(s1.length() + 1, vector<bool> (s2.length() + 1, false));
		for (size_t i = 0; i <= s1.length(); ++ i) {
			for (size_t j = 0; j <= s2.length(); ++ j) {
				dp[i][j] = ((0 == i && 0 == j) || (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]));
			}
		}
		return dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
    }
};

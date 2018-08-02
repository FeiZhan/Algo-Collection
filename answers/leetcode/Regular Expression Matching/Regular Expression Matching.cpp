//@result 445 / 445 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 0 minutes ago You are here! Your runtime beats 55.16% of cpp submissions.

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.length() + 1, vector<bool> (p.length() + 1, false));
        dp[0][0] = true;
        for (size_t i = 0; i <= s.length(); ++ i) {
            for (size_t j = 1; j <= p.length(); ++ j) {
                switch (p[j - 1]) {
                case '.':
                    dp[i][j] = i > 0 && dp[i - 1][j - 1];
                    break;
                case '*':
                    if (j > 1) {
                        dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
                    }
                    break;
                default:
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                    break;
                }
            }
        }
        return dp.back().back();
    }
};

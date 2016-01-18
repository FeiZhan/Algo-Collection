//@result Accepted 100% Total Runtime: 21 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *ss, const char *pp) {
        // write your code here
        string s(ss);
        string p(pp);
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

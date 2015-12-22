class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector<vector<int> > dp(S.length(), vector<int> (T.length(), 0));
        for (size_t i = 0; i < S.length(); ++ i) {
            for (size_t j = 0; j < T.length(); ++ j) {
                if (S[i] == T[j]) {
                    dp[i][j] += (i > 0 && j > 0) ? dp[i - 1][j - 1] : ((i > 0 || (0 == i && 0 == j)) ? 1 : 0);
                }
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        return dp.back().back();
    }
};

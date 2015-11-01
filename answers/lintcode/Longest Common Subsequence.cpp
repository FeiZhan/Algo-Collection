//@level Medium 
//@type LintCode Copyright Longest Common Subsequence Dynamic Programming
//@result Accepted Total Runtime: 10 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
		vector<vector<int> > dp(A.length(), vector<int> (B.length(), 0));
		for (size_t i = 0; i < A.length(); ++ i) {
			for (size_t j = 0; j < B.length(); ++ j) {
				if (A[i] == B[j]) {
					dp[i][j] = (0 == i || 0 == j) ? 1 : dp[i - 1][j - 1] + 1;
				}
				else if (i > 0 && j > 0) {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp.size() ? dp[dp.size() - 1][dp[dp.size() - 1].size() - 1] : 0;
    }
};


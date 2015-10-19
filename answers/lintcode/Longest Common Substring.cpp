//@level Medium 
//@type LintCode Copyright Longest Common Subsequence Dynamic Programming
//@result Accepted Total Runtime: 20 ms 100% test cases passed.

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
		vector<vector<int> > dp(A.length(), vector<int> (B.length(), 0));
		int longest(0);
		for (size_t i = 0; i < A.length(); ++ i) {
			for (size_t j = 0; j < B.length(); ++ j) {
				if (A[i] == B[j]) {
					dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + 1 : 1;
					longest = max(longest, dp[i][j]);
				}
			}
		}
		return longest;
    }
};


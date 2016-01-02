class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (size_t i = 1; i <= n; ++ i) {
			for (size_t j = 0; j < i; ++ j) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
    }
};

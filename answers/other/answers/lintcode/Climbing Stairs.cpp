class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (size_t i = 0; i <= n; ++ i) {
			if (dp[i]) {
				if (i + 1 <= n) {
					dp[i + 1] += dp[i];
				}
				if (i + 2 <= n) {
					dp[i + 2] += dp[i];
				}
			}
		}
		return dp[n];
    }
};


// 2014-12-24
//@result 45 / 45 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 2.79% of cpp submissions.

class Solution {
public:
    int climbStairs(int n) {
		std::vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++ i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
    }
};

//@result 180 / 180 test cases passed. Status: Accepted Runtime: 180 ms Submitted: 3 days, 22 hours ago You are here! Your runtime beats 29.39% of cpp submissions.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (size_t i = 1; i < dp.size(); ++ i) {
            for (size_t j = 0; j < coins.size(); ++ j) {
                if (i >= coins[j] && dp[i - coins[j]] < INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] < INT_MAX ? dp[amount] : -1;
    }
};
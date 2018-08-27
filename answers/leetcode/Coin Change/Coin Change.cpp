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

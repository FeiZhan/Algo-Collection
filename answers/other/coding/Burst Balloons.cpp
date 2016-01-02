class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int> (nums.size(), 0));
        for (size_t i = 0; i < nums.size(); ++ i) {
            for (size_t j = 0; i + j < nums.size(); ++ j) {
                for (size_t k = j; k <= i + j; ++ k) {
                    int current = nums[k];
                    if (j > 0) {
                        current *= nums[j - 1];
                    }
                    if (i + j + 1 < nums.size()) {
                        current *= nums[i + j + 1];
                    }
                    if (j <= k - 1) {
                        current += dp[j][k - 1];
                    }
                    if (k + 1 <= i + j) {
                        current += dp[k + 1][i + j];
                    }
                    dp[j][i + j] = max(dp[j][i + j], current);
                }
            }
        }
        return nums.size() ? dp[0][nums.size() - 1] : 0;
    }
};
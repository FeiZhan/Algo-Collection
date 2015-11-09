class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);
        int length = nums.size() > 0;
        for (size_t i = 0; i < dp.size(); ++ i) {
            for (size_t j = 0; j < i; ++ j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    length = max(length, dp[i]);
                }
            }
        }
        return length;
    }
};
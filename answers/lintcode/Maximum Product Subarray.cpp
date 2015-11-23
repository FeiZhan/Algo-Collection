class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        vector<int> max_dp(nums.size(), INT_MIN);
        vector<int> min_dp(nums.size(), INT_MAX);
        int max_product = INT_MIN;
        for (size_t i = 0; i < nums.size(); ++ i) {
            max_dp[i] = max(nums[i], (i > 0 ? max(max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]) : INT_MIN));
            min_dp[i] = min(nums[i], (i > 0 ? min(max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]) : INT_MAX));
            max_product = max(max_product, max_dp[i]);
        }
        return max_product;
    }
};

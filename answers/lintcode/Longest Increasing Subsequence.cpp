class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
		vector<int> dp(nums.size(), 1);
		for (size_t i = 0; i < nums.size(); ++ i) {
			for (size_t j = 0; j < i; ++ j) {
				if (nums[j] <= nums[i]) {
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
		}
		int longest(0);
		for (size_t i = 0; i < dp.size(); ++ i) {
			longest = max(longest, dp[i]);
		}
		return longest;
    }
};


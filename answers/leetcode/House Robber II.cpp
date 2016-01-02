//@type Dynamic Programming
//@result 74 / 74 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 12.88% of cpp submissions.

class Solution {
public:
    int rob(vector<int>& nums) {
		if (0 == nums.size()) {
			return 0;
		}
		if (1 == nums.size()) {
			return nums[0];
		}
        vector<int> nums1(nums.begin() + 1, nums.end());
		nums.pop_back();
		return max(rob1(nums), rob1(nums1));
    }
    // reuse previous code
    int rob1(vector<int>& nums) {
		if (0 == nums.size()) {
			return 0;
		}
        vector<int> dp(nums.size(), 0);
		for (size_t i = 0; i < nums.size(); ++ i) {
			dp[i] = max(dp[i], nums[i]);
			if (i > 0) {
				dp[i] = max(dp[i], dp[i - 1]);
				if (i > 1) {
					dp[i] = max(dp[i], dp[i - 2] + nums[i]);
				}
			}
		}
		return dp[nums.size() - 1];
    }
};

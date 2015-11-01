class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if (0 == nums.size()) {
			return 0;
		}
        int local = nums[0];
        int global = nums[0];
        for (size_t i = 1; i < nums.size(); ++ i) {
			local = min(local + nums[i], nums[i]);
			global = min(global, local);
		}
		return global;
    }
};


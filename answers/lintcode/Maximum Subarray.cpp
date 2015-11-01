class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (0 == nums.size()) {
			return 0;
		}
        int local = nums[0];
        int global = nums[0];
        for (size_t i = 1; i < nums.size(); ++ i) {
			local = max(local + nums[i], nums[i]);
			global = max(global, local);
		}
		return global;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int num = INT_MAX;
        int count = 0;
        for (size_t i = 0; i < nums.size(); ++ i) {
        	if (0 == count) {
        		num = nums[i];
        	}
        	count += num == nums[i] ? 1 : -1;
        }
        return num;
    }
};


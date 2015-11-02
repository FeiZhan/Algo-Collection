class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int major0 = INT_MAX;
        int count0 = 0;
        int major1 = INT_MAX;
        int count1 = 0;
        for (size_t i = 0; i < nums.size(); ++ i) {
        	if (0 == count0) {
        		major0 = nums[i];
        	}
        	if (0 == count1 && nums[i] != major0) {
        		major1 = nums[i];
        	}
        	if (major0 == nums[i]) {
        		++ count0;
        	}
        	else if (major1 == nums[i]) {
        		++ count1;
        	}
        	else {
        		-- count0;
        		-- count1;
        	}
        }
        count0 = 0;
        count1 = 0;
        for (size_t i = 0; i < nums.size(); ++ i) {
        	if (nums[i] == major0) {
        		++ count0;
        	}
        	if (nums[i] == major1) {
        		++ count1;
        	}
        }
        return count0 >= count1 ? major0 : major1;
    }
};


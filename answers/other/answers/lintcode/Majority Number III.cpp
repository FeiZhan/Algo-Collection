class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        map<int, int> num_map;
        for (size_t i = 0; i < nums.size(); ++ i) {
        	if (num_map.end() == num_map.find(nums[i])) {
        		num_map[nums[i]] = 0;
        	}
        	++ num_map[nums[i]];
        }
        for (map<int, int>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
        	if (it->second * k > nums.size()) {
        		return it->first;
        	}
        }
        return 0;
    }
};


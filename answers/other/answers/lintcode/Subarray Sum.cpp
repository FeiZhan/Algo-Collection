class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
		vector<int> ans;
		map<int, size_t> sum_map;
		int sum = 0;
		for (size_t i = 0; i < nums.size(); ++ i) {
			sum += nums[i];
			if (0 == sum || sum_map.end() != sum_map.find(sum)) {
				ans.push_back(sum ? sum_map[sum] + 1 : 0);
				ans.push_back(i);
				break;
			}
			sum_map[sum] = i;
		}
		return ans;
    }
};

//@type Array Math Bit Manipulation
//@result 121 / 121 test cases passed. Status: Accepted Runtime: 36 ms Submitted: 4 minutes ago

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum((0 + nums.size()) * (nums.size() + 1) / 2);
		for (size_t i = 0; i < nums.size(); ++ i) {
			sum -= nums[i];
		}
		return sum;
    }
};
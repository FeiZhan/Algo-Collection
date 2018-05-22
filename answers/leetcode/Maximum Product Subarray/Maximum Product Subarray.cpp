//@result 183 / 183 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 78.37% of cpp submissions.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if (0 == nums.size()) {
			return 0;
		}
		int max = nums[0], min = nums[0];
		int all_max = max;
		for (int i = 1; i < nums.size(); ++ i) {
			// put them first, don't use polluted max, min
			int temp0 = max * nums[i];
			int temp1 = min * nums[i];
			// reset them
			max = nums[i];
			min = nums[i];
			if (temp0 > max) {
				max = temp0;
			}
			if (temp0 < min) {
				min = temp0;
			}
			if (temp1 > max) {
				max = temp1;
			}
			if (temp1 < min) {
				min = temp1;
			}
			if (max > all_max) {
				all_max = max;
			}
		}
		return all_max;
    }
};

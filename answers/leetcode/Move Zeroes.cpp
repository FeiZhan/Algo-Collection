//@type  Array Two Pointers
//@result 21 / 21 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		size_t j = 0;
		for (size_t i = 0; i < nums.size(); ++ i, ++ j) {
			if (0 == nums[i]) {
				-- j;
			}
			else {
				nums[j] = nums[i];
			}
		}
		for (; j < nums.size(); ++ j) {
			nums[j] = 0;
		}
    }
};
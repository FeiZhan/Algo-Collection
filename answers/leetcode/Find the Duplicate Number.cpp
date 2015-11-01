//@type Array Two Pointers Binary Search
//@result 53 / 53 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		return findDuplicate(nums, 1, nums.size());
	}
    int findDuplicate(const vector<int>& nums, int left, int right) {
        if (left >= right) {
			return 0;
		}
		else if (left + 1 == right) {
			return left;
		}
		int middle = (left + right - 1) / 2;
		int count(0);
		for (size_t i = 0; i < nums.size(); ++ i) {
			if (nums[i] <= middle) {
				++ count;
			}
		}
		if (count > middle) {
			return findDuplicate(nums, left, middle + 1);
		}
		else {
			return findDuplicate(nums, middle + 1, right);
		}
    }
};
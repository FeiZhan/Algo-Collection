//@type Array Two Pointers Binary Search
//@result 13 / 13 test cases passed. Status: Accepted Runtime: 8 ms You are here! Your runtime beats 11.63% of cpp submissions.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		if (0 == nums.size()) {
			return 0;
		}
        size_t left(0), right(0);
		int sum(0);
		int min_len(INT_MAX);
		while (left < nums.size() && right <= nums.size()) {
			if (sum < s && right + 1 <= nums.size()) {
				sum += nums[right];
				++ right;
			}
			else if (sum >= s && left + 1 <= right) {
				sum -= nums[left];
				++ left;
			}
			else {
				break;
			}
			if (sum >= s && min_len > right - left) {
				min_len = right - left;
			}
		}
		return INT_MAX == min_len ? 0 : min_len;
    }
};

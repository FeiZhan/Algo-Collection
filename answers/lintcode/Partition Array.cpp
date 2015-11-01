class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
		size_t left(0);
		size_t right(nums.size() - 1);
		while (left <= right && left < nums.size() && right < nums.size()) {
			// should be put in the first place
			if (nums[left] >= k && nums[right] < k) {
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			}
			if (nums[left] < k) {
				++ left;
			}
			if (nums[right] >= k) {
				-- right;
			}
		}
		return left;
    }
};

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
		if (0 == nums.size()) {
			return;
		}
		size_t left = 0;
		size_t right = nums.size() - 1;
		while (left < right) {
			if (nums[left] % 2 == 0 && nums[right] % 2 == 1) {
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			}
			if (nums[left] % 2 == 1) {
				++ left;
			}
			if (nums[right] % 2 == 0) {
				-- right;
			}
		}
    }
};

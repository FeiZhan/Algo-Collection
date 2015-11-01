class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
		size_t target(INT_MAX);
		for (size_t i = nums.size() - 2; i < nums.size(); -- i) {
			if (nums[i] < nums[i + 1]) {
				target = i;
				break;
			}
		}
		if (INT_MAX == target) {
			sort(nums.begin(), nums.end());
			return nums;
		}
		size_t change(target + 1);
		for (size_t i = nums.size() - 1; i < nums.size(); -- i) {
			if (nums[i] > nums[target]) {
				change = i;
				break;
			}
		}
		int temp = nums[target];
		nums[target] = nums[change];
		nums[change] = temp;
		sort(nums.begin() + target + 1, nums.end());
		return nums;
    }
};

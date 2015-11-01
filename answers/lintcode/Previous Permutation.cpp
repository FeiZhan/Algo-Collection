class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
		size_t target(INT_MAX);
		for (size_t i = nums.size() - 2; i < nums.size(); -- i) {
			if (nums[i] > nums[i + 1]) {
				target = i;
				break;
			}
		}
		if (INT_MAX == target) {
			sort(nums.begin(), nums.end(), greater<int> ());
			return nums;
		}
		size_t change(target + 1);
		for (size_t i = target + 1; i < nums.size(); ++ i) {
			if (nums[i] < nums[target] && nums[i] > nums[change]) {
				change = i;
			}
		}
		int temp = nums[target];
		nums[target] = nums[change];
		nums[change] = temp;
		sort(nums.begin() + target + 1, nums.end(), greater<int> ());
		return nums;
    }
};

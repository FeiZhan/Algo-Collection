class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
		vector<int> left_max(nums.size(), INT_MIN);
		for (size_t i = 0; i < left_max.size(); ++ i) {
			left_max[i] = max((i > 0 ? left_max[i - 1] : 0) + nums[i], nums[i]);
		}
		for (size_t i = 0; i < left_max.size(); ++ i) {
			left_max[i] = max((i > 0 ? left_max[i - 1] : INT_MIN), left_max[i]);
		}
		vector<int> left_min(nums.size(), INT_MAX);
		for (size_t i = 0; i < left_min.size(); ++ i) {
			left_min[i] = min((i > 0 ? left_min[i - 1] : 0) + nums[i], nums[i]);
		}
		for (size_t i = 0; i < left_min.size(); ++ i) {
			left_min[i] = min((i > 0 ? left_min[i - 1] : INT_MAX), left_min[i]);
		}
		vector<int> right_max(nums.size(), INT_MIN);
		for (size_t i = right_max.size() - 1; i < right_max.size(); -- i) {
			right_max[i] = max((i + 1 < right_max.size() ? right_max[i + 1] : 0) + nums[i], nums[i]);
		}
		for (size_t i = right_max.size() - 1; i < right_max.size(); -- i) {
			right_max[i] = max((i + 1 < right_max.size() ? right_max[i + 1] : INT_MIN), right_max[i]);
		}
		vector<int> right_min(nums.size(), INT_MAX);
		for (size_t i = right_min.size() - 1; i < right_min.size(); -- i) {
			right_min[i] = min((i + 1 < right_min.size() ? right_min[i + 1] : 0) + nums[i], nums[i]);
		}
		for (size_t i = right_min.size() - 1; i < right_min.size(); -- i) {
			right_min[i] = min((i + 1 < right_min.size() ? right_min[i + 1] : INT_MAX), right_min[i]);
		}
		int max_two(INT_MIN);
		for (size_t i = 1; i < nums.size(); ++ i) {
			//cout << "test " << i << " " << left[i] << " " << right[right.size() - 1 - i] << endl;
			max_two = max(max_two, max(left_max[i - 1] - right_min[i], right_max[i] - left_min[i - 1]));
		}
		return max_two;
    }
};
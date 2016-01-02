class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        size_t begin = 0;
        for (size_t i = 1; i < nums.size(); ++ i) {
			if (nums[i - 1] > nums[i]) {
				begin = i;
			}
		}
		reverse(nums.begin(), nums.begin() + begin);
		reverse(nums.begin() + begin, nums.end());
		reverse(nums.begin(), nums.end());
    }
};

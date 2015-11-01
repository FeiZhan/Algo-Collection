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
		for (size_t i = begin - 1; i < nums.size(); -- i) {
			for (size_t j = begin; j < nums.size() - i)
		}
    }
};

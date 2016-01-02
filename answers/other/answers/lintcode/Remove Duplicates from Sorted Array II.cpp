class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
		size_t remain = 2;
		for (size_t i = 2; i < nums.size(); ++ i) {
			if (nums[i] != nums[remain - 1] || nums[i] != nums[remain - 2]) {
				nums[remain] = nums[i];
				++ remain;
			}
		}
		return nums.size() > remain ? remain : nums.size();
    }
};

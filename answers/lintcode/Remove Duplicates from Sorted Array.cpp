class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
		size_t remain = 1;
		for (size_t i = 1; i < nums.size(); ++ i) {
			if (nums[remain - 1] != nums[i]) {
				nums[remain] = nums[i];
				++ remain;
			}
		}
		return nums.size() ? remain : 0;
    }
};

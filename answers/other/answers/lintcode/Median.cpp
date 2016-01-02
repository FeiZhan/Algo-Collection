class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        return nums[(nums.size() - 1) / 2];
    }
};


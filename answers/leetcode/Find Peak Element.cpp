//@result 58 / 58 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 95.79% of cpp submissions

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t left = 0;
        size_t right = nums.size() - 1;
        while (left <= right && right < nums.size()) {
            size_t middle = (left + right) / 2;
            if ((0 == middle || nums[middle - 1] < nums[middle]) && (nums.size() == middle + 1 || nums[middle] > nums[middle + 1])) {
                return middle;
            }
            else if (middle > 0 && nums[middle - 1] > nums[middle] && (nums.size() == middle + 1 || nums[middle] > nums[middle + 1])) {
                right = middle - 1;
            }
            else if ((0 == middle || nums[middle - 1] < nums[middle]) && middle + 1 < nums.size() && nums[middle] < nums[middle + 1]) {
                left = middle + 1;
            }
            else {
                ++ left;
            }
        }
        return nums.size();
    }
};

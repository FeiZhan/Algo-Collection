//@result 156 / 156 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 5.47% of cpp submissions.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
                -- i;
            }
        }
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (nums[i] - 1 != i) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
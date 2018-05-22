//@result 61 / 61 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min0 = INT_MAX;
        int min1 = INT_MAX;
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (nums[i] <= min0) {
                min0 = nums[i];
            }
            else if (nums[i] <= min1) {
                min1 = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};
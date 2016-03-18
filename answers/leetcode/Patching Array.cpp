//@result 149 / 149 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 39.94% of cppsubmissions.

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 1;
        int count = 0;
        size_t i = 0;
        while (sum <= n) {
            if (i >= nums.size() || sum < nums[i]) {
                nums.insert(nums.begin() + i, sum);
                ++ count;
            }
            sum += nums[i];
            ++ i;
        }
        return count;
    }
};
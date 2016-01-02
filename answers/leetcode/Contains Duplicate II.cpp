//@time complexity O(n)
//@space complexity O(n)
//@result 20 / 20 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 0 minutes ago You are here! Your runtime beats 45.89% of cpp submissions.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, size_t> num_map;
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (num_map.end() != num_map.find(nums[i]) && i - num_map[nums[i]] <= k) {
                return true;
            }
            num_map[nums[i]] = i;
        }
        return false;
    }
};

//@type  Array Hash Table
//@result 16 / 16 test cases passed. Status: Accepted Runtime: 52 ms Submitted: 0 minutes ago You are here! Your runtime beats 37.29% of cpp submissions

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
		return nums.size() != num_set.size();
    }
};

//@type Array Hash Table
//@result 19 / 19 test cases passed. Status: Accepted Runtime: 188 ms Submitted: 0 minutes ago You are here! Your runtime beats 0.42% of cpp submissions.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<size_t> > num_map;
		for (size_t i = 0; i < nums.size(); ++ i) {
			if (num_map.end() == num_map.find(nums[i])) {
				num_map.insert(make_pair(nums[i], vector<size_t> ()));
			}
			num_map[nums[i]].push_back(i);
		}
		for (map<int, vector<size_t> >::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
			for (size_t i = 1; i < it->second.size(); ++ i) {
				if (it->second[i] - it->second[i - 1] <= k) {
					return true;
				}
			}
		}
		return false;
    }
};
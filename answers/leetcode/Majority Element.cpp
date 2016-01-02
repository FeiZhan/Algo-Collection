//@result 42 / 42 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 0 minutes ago You are here! Your runtime beats 44.24% of cpp submissions

class Solution {
public:
	int majorityElement(vector<int> &num) {
		unordered_map<int, int> num_map;
		for (size_t i = 0; i < num.size(); ++ i) {
			++ num_map[num[i]];
		}
		int majority = 0;
		int max_count = 0;
		for (unordered_map<int, int>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
			if (it->second > max_count) {
				majority = it->first;
				max_count = it->second;
			}
		}
		return majority;
	}
};

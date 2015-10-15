class Solution {
public:
	int majorityElement(vector<int> &num) {
		std::map<int, int> num_map;
		for (size_t i = 0; i < num.size(); ++ i) {
			++ num_map[num[i]];
		}
		int majority = 0;
		int max_count = 0;
		for (std::map<int, int>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
			if (it->second > max_count) {
				majority = it->first;
				max_count = it->second;
			}
		}
		return majority;
	}
};
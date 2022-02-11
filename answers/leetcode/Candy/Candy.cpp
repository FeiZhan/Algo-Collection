class Solution {
public:
	int candy(vector<int> &ratings) {
		std::multimap<int, size_t> child_map;
		for (size_t i = 0; i < ratings.size(); ++ i) {
			child_map.insert(make_pair(ratings[i], i));
		}
		vector<int> candy_list(ratings.size(), 0);
		for (std::multimap<int, size_t>::iterator it = child_map.begin(); it != child_map.end(); ++ it) {
			if (candy_list[it->second] <= 0) {
				candy_list[it->second] = 1;
				for (size_t i = it->second + 1; i < ratings.size(); ++ i) {
					if (ratings[i] > ratings[i - 1] && candy_list[i] < candy_list[i - 1] + 1) {
						candy_list[i] = candy_list[i - 1] + 1;
					} else {
						break;
					}
				}
				for (size_t i = it->second - 1; i < ratings.size(); -- i) {
					if (ratings[i] > ratings[i + 1] && candy_list[i] < candy_list[i + 1] + 1) {
						candy_list[i] = candy_list[i + 1] + 1;
					} else {
						break;
					}
				}
			}
		}
		int candy_sum = 0;
		for (size_t i = 0; i < candy_list.size(); ++ i) {
			candy_sum += candy_list[i];
		}
		return candy_sum;
	}
};

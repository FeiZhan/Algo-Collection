class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		for (size_t i = 0; i < num.size(); ++ i) {
			++ num_map[num[i]];
		}
		vector<int> temp;
		return combinationSum2(temp, num_map.begin(), target);
	}
	vector<vector<int> > combinationSum2(vector<int> &combin, std::map<int, int>::iterator begin, int target) {
		vector<vector<int> > ans;
		if (0 == target) {
			ans.push_back(combin);
		}
		if (num_map.end() == begin) {
			return ans;
		}
		for (std::map<int, int>::iterator it = begin; it != num_map.end(); ++ it) {
			if (it->first > target) {
				break;
			}
			for (int i = 0; i < it->second; ++ i) {
				combin.push_back(it->first);
				vector<vector<int> > temp = combinationSum2(combin, std::next(it), target - it->first * (i + 1));
				ans.insert(ans.end(), temp.begin(), temp.end());
			}
			for (int i = 0; i < it->second; ++ i) {
				combin.pop_back();
			}
		}
		return ans;
	}
	std::map<int, int> num_map;
};

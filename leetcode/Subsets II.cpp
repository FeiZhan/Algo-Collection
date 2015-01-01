class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		for (size_t i = 0; i < S.size(); ++ i) {
			++ num_map[S[i]];
		}
		return subsets(num_map.begin());
	}
	vector<vector<int> > subsets(map<int, int>::iterator begin) {
		vector<vector<int> > ans;
		if (num_map.end() == begin) {
			ans.push_back(vector<int> ());
			return ans;
		}
		vector<vector<int> > temp_ans = subsets(std::next(begin));
		ans.insert(ans.end(), temp_ans.begin(), temp_ans.end());
		for (size_t i = 0; i < temp_ans.size(); ++ i) {
			for (int j = 0; j < begin->second; ++ j) {
				temp_ans[i].insert(temp_ans[i].begin(), begin->first);
				ans.push_back(temp_ans[i]);
			}
		}
		return ans;
	}
	map<int, int> num_map;
};

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		set<vector<int> > ans_set = permuteUnique(num.begin(), num.end());
		vector<vector<int> > ans(ans_set.begin(), ans_set.end());
		return ans;
	}
	set<vector<int> > permuteUnique(vector<int>::iterator begin, vector<int>::iterator end) {
		set<vector<int> > ans;
		if (end == begin) {
			ans.insert(vector<int> ());
			return ans;
		}
		set<vector<int> > temp_ans = permuteUnique(std::next(begin), end);
		for (set<vector<int> >::iterator it = temp_ans.begin(); it != temp_ans.end(); ++ it) {
			for (size_t j = 0; j <= it->size(); ++ j) {
				vector<int> temp(*it);
				temp.insert(temp.begin() + j, *begin);
				ans.insert(temp);
			}
		}
		return ans;
	}
};

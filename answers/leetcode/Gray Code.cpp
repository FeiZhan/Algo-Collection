class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		for (int i = 0; i < n; ++i) {
			int highest_bit = 1 << i;
			int len = ans.size();
			for (int j = len - 1; j >= 0; --j) {
				ans.push_back(highest_bit + ans[j]);
			}
		}
		return ans;
	}
};
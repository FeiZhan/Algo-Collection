//@result 1158 / 1158 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 0 minutes ago You are here! Your runtime beats 25.55% of cpp submissions.

class Solution {
public:
    string convert(string s, int nRows) {
		vector<string> row_list(nRows);
		size_t pos = 0;
		while (pos < s.length()) {
			for (int i = 0; i < nRows; ++ i) {
				if (pos >= s.length()) {
					break;
				}
				row_list[i] += s[pos];
				++ pos;
			}
			for (int i = nRows - 2; i >= 1; -- i) {
				if (pos >= s.length()) {
					break;
				}
				row_list[i] += s[pos];
				++ pos;
			}
		}
		string ans;
		for (size_t i = 0; i < row_list.size(); ++ i) {
			ans += row_list[i];
		}
		return ans;
    }
};

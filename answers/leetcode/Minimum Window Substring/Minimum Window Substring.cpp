//@result 266 / 266 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago You are here! Your runtime beats 48.28% of cpp submissions.

class Solution {
public:
	string minWindow(string S, string T) {
		if (0 == S.size() || S.size() < T.size()) {
			return "";
		}
		vector<int> appear_count(256, 0);
		vector<int> expect_count(256, 0);
		for (size_t i = 0; i < T.size(); ++ i) {
			++expect_count[T[i]];
		}
		size_t min_v = INT_MAX, min_start = 0;
		int wid_start = 0;
		int appeared = 0;
		for (size_t wid_end = 0; wid_end < S.size(); ++ wid_end) {
			if (expect_count[S[wid_end]] > 0) {
				++ appear_count[S[wid_end]];
				if (appear_count[S[wid_end]] <= expect_count[S[wid_end]]) {
					++appeared;
				}
			}
			if (appeared == T.size()) {
				while (appear_count[S[wid_start]] > expect_count[S[wid_start]] || 0 == expect_count[S[wid_start]]) {
					-- appear_count[S[wid_start]];
					++wid_start;
				}
				if (min_v > wid_end - wid_start + 1) {
					min_v = wid_end - wid_start + 1;
					min_start = wid_start;
				}
			}
		}
		if (INT_MAX == min_v) {
			return "";
		}
		return S.substr(min_start, min_v);
	}
};

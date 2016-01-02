//@result 1000 / 1000 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 8.80% of cpp submissions.

class Solution {
public:
	int titleToNumber(string s) {
		size_t pos = 0;
		int title = 0;
		while (pos < s.length()) {
			title = title * 26 + static_cast<int> (s[pos ++] - 'A') + 1;
		}
		return title;
	}
};

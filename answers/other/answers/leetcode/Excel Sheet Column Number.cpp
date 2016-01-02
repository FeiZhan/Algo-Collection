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

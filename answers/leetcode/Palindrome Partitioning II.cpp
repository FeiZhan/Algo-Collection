// http://fisherlei.blogspot.ca/2013/03/leetcode-palindrome-partitioning-ii.html
//@type dp
class Solution {
public:
	int minCut(string s) {
		size_t len = s.size();
		int d[len + 1];
		bool p[len][len];
		for (size_t i = 0; i <= len; ++i) {
			d[i] = len - i;
		}
		for (size_t i = 0; i < len; ++i) {
			for (size_t j = 0; j < len; ++j) {
				p[i][j] = false;
			}
		}
		for (size_t i = len - 1; i < len; --i) {
			for (size_t j = i; j < len; ++j) {
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
					p[i][j] = true;
					d[i] = min(d[i], d[j + 1] + 1);
				}
			}
		}
		return d[0] - 1;
	}
};
// 2015-1-3
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (NULL == s || 0 == strlen(s)) {
			return 0;
		}
		size_t start = 0, end = 0;
		for (size_t i = 1; i < strlen(s); ++ i) {
			if (' ' == s[i - 1] && ' ' != s[i]) {
				start = i;
			}
			if (' ' != s[i]) {
				end = i;
			}
		}
		if (' ' != s[start]) {
			return end - start + 1;
		} else {
			return 0;
		}
	}
};

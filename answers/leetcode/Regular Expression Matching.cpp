class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (0 == strlen(p)) {
			return 0 == strlen(s);
		}
		if (1 == strlen(p)) {
			if (strlen(s) < 1) {
				return false;
			}
			else if (p[0] != s[0] && p[0] != '.') {
				return false;
			} else {
				return isMatch(s + 1, p + 1);
			}
		}
		if ('*' != p[1]) {
			if (strlen(s) < 1) {
				return false;
			}
			if (p[0] != s[0] && p[0] != '.') {
				return false;
			} else {
				return isMatch(s + 1, p + 1);
			}
		} else {
			if (isMatch(s, p + 2)) {
				return true;
			}
			int i = 0;
			while (i < strlen(s) && (s[i] == p[0] || p[0] == '.')) {
				if (isMatch(s + i + 1, p + 2)) {
					return true;
				}
				++ i;
			}
			return false;
		}
	}
};

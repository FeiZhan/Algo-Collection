class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		bool star = false;
		const char *str = NULL, *ptr = NULL;
		for (str = s, ptr = p; *str; ++ str, ++ ptr) {
			switch (*ptr) {
			case '?':
				break;
			case '*':
				star = true;
				s = str;
				p = ptr;
				while ('*' == *p) {
					++ p;
				}
				if ('\0' == *p) {
					return true;
				}
				str = s - 1;
				ptr = p - 1;
				break;
			default:
				if (*str != *ptr) {
					if (!star) {
						return false;
					}
					++ s;
					str = s - 1;
					ptr = p - 1;
				}
			}
		}
		while ('*' == *ptr) {
			++ ptr;
		}
		return '\0' == *ptr;
	}
};
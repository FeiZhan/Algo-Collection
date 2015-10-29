class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
		if (NULL == source || NULL == target) {
			return -1;
		}
		else if ('\0' == target[0]) {
			return 0;
		}
		int i = 0;
		while (source[i]) {
			int j = 0;
			bool flag = true;
			while (target[j]) {
				if (source[i + j] != target[j]) {
					flag = false;
					break;
				}
				++ j;
			}
			if (flag) {
				return true;
			}
			++ i;
		}
        return -1;
    }
};



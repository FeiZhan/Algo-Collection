class Solution {
public:
    int compareVersion(string version1, string version2) {
		size_t prev1 = 0, prev2 = 0;
		while (prev1 < version1.length() && prev2 < version2.length()) {
			size_t i = 0;
			for (i = prev1; i < version1.length(); ++ i) {
				if ('.' == version1[i]) {
					break;
				}
			}
			int v1 = atoi(version1.substr(prev1, i - prev1).c_str());
			prev1 = i + 1;
			i = 0;
			for (i = prev2; i < version2.length(); ++ i) {
				if ('.' == version2[i]) {
					break;
				}
			}
			int v2 = atoi(version2.substr(prev2, i - prev2).c_str());
			prev2 = i + 1;
			if (v1 != v2) {
				//@note precedency
				return (v1 > v2) - (v1 < v2);
			}
		}
		if (version1.size() > prev1) {
			int v = atoi(version1.substr(prev1).c_str());
			//@note
			if (v > 0) {
				return 1;
			}
		}
		if (version2.size() > prev2) {
			int v = atoi(version2.substr(prev2).c_str());
			if (v > 0) {
				return -1;
			}
		}
		return 0;
    }
};

//@result 71 / 71 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 10.86% of cpp submissions.

class Solution {
public:
    int compareVersion(string version1, string version2) {
		size_t prev1 = 0, prev2 = 0;
		while (prev1 < version1.length() || prev2 < version2.length()) {
			size_t i = 0;
			for (i = prev1; i < version1.length(); ++ i) {
				if ('.' == version1[i]) {
					break;
				}
			}
			int v1 = (i > prev1) ? atoi(version1.substr(prev1, i - prev1).c_str()) : 0;
			prev1 = i + 1;
			i = 0;
			for (i = prev2; i < version2.length(); ++ i) {
				if ('.' == version2[i]) {
					break;
				}
			}
			int v2 = (i > prev2) ? atoi(version2.substr(prev2, i - prev2).c_str()) : 0;
			prev2 = i + 1;
            //cout << "debug " << v1 << " " << v2 << endl;
			if (v1 != v2) {
				//@note precedency
				return (v1 > v2) - (v1 < v2);
			}
		}
		return 0;
    }
};

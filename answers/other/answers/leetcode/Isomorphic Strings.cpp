//@type Hash Table
//@result 30 / 30 test cases passed. Status: Accepted Runtime: 92 ms Submitted: 0 minutes ago You are here! Your runtime beats 7.83% of cpp submissions.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> iso_map[2];
		for (size_t i = 0; i < s.length() && i < t.length(); ++ i) {
			if (iso_map[0].end() != iso_map[0].find(s[i])) {
				if (iso_map[0][s[i]] != t[i]) {
					return false;
				}
			} else {
				iso_map[0][s[i]] = t[i];
			}
			if (iso_map[1].end() != iso_map[1].find(t[i])) {
				if (iso_map[1][t[i]] != s[i]) {
					return false;
				}
			} else {
				iso_map[1][t[i]] = s[i];
			}
		}
		return true;
    }
};
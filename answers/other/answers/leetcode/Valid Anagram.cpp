//@type Hash Table Sort
//@result 32 / 32 test cases passed. Status: Accepted Runtime: 100 ms Submitted: 0 minutes ago You are here! Your runtime beats 8.22% of cpp submissions.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
		return s == t;
    }
};
//@result 229 / 229 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 11.28% of cpp submissions.

class Solution {
public:
	int longestValidParentheses(string s) {
		size_t len_max = 0;
		stack<size_t> sta;
		size_t p = 0;
		while (s[p]) {
			if ('(' == s[p]) {
				sta.push(p);
			}
			else {
				if (! sta.empty() && '(' == s[sta.top()]) {
					sta.pop();
					len_max = max(len_max, p - (sta.empty() ? -1 : sta.top()));
				}
				else {
					sta.push(p);
				}
			}
			++ p;
		}
		return len_max;
	}
};

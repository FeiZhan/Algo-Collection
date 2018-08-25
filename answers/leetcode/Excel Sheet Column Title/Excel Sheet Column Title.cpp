//@result 18 / 18 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 0.25% of cpp submissions.

class Solution {
public:
	string convertToTitle(int n) {
		string title;
		while (n > 0) {
			title = static_cast<char> ((n - 1) % 26 + 'A') + title;
			n = (n - 1) / 26;
		}
		if (title.length() == 0) {
			title = string("A");
		}
		return title;
	}
};

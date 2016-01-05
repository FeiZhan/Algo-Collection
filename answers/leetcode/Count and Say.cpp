// 2014-12-18
//@result 18 / 18 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 65.89% of cpp submissions.

class Solution {
public:
    string countAndSay(int n) {
		string ans("1");
		for (int i = 0; i < n - 1; ++ i) {
			string new_ans;
			int count = 1;
			for (size_t j = 1; j <= ans.size(); ++ j) {
				if (ans.size() == j) {
					new_ans += static_cast<char> (count + '0');
					new_ans += ans[j - 1];
				}
				else if (ans[j] == ans[j - 1]) {
					++ count;
				}
				else {
					new_ans += static_cast<char> (count + '0');
					new_ans += ans[j - 1];
					count = 1;
				}
			}
			ans = new_ans;
		}
		return ans;
    }
};

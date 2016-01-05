//@result 88 / 88 test cases passed. Status: Accepted Runtime: 172 ms Submitted: 0 minutes ago You are here! Your runtime beats 25.38% of cpp submissions.
class Solution {
public:
    string longestPalindrome(string s) {
		// don't use vector<vector>
        bool dp[1010][1010] = {false};
        bool same_flag = true;
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++ i) {
            dp[0][i] = true;
        }
        for (int i = 0; i + 1 < s.length(); ++ i) {
            if (s[i] == s[i + 1]) {
                dp[1][i] = true;
                max_len = 1;
                start = i;
            }
        }
        for (int i = 2; i < s.length(); ++ i) {
            for (int j = 0; i + j < s.length(); ++ j) {
                if (dp[i - 2][j + 1] && s[j] == s[j + i]) {
                    dp[i][j] = true;
                    max_len = i;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len + 1);
    }
};

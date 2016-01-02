class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        std::vector<std::vector<bool> > dp(s.length(), std::vector<bool> (s.length(), false));
        size_t left = 0;
        size_t length = 0;
        for (size_t i = 0; i < s.length(); ++ i) {
            for (size_t j = 0; i + j < s.length(); ++ j) {
                dp[i][j] = 0 == i || (s[j] == s[j + i] && (i <= 1 || dp[i - 2][j + 1]));
                if (dp[i][j] && i > length) {
                    left = j;
                    length = i;
                }
            }
        }
        return s.substr(left, length + 1);
    }
};

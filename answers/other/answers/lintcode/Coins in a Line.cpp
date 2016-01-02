// innovative

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        vector<bool> dp(n, false);
        for (int i = 0; i < n; ++ i) {
            if (i < 2) {
                dp[i] = true;
            }
            if (dp[i]) {
                if (i + 3 < n) {
                    dp[i + 3] = true;
                }
            }
            else {
                if (i + 2 < n) {
                    dp[i + 2] = true;
                }
            }
        }
        return n ? dp[n - 1] : false;
    }
};

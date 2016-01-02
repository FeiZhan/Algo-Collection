//@result WA

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        vector<int> dp(values.size(), 0);
        for (size_t i = 0; i < values.size(); ++ i) {
            if (0 == i) {
                dp[i] = values[i];
            }
            else if (1 == i) {
                dp[i] = values[i - 1] + values[i];
            }
            else if (2 == i) {
                dp[i] = min(dp[i - 2] + values[i], dp[i - 1]);
            }
            else if (3 == i) {
                dp[i] = min(values[i] + min(dp[i - 2], dp[i - 3]), values[i] + values[i - 1] + dp[i - 3]);
            } else {
                dp[i] = max(values[i] + min(dp[i - 2], dp[i - 3]), values[i] + values[i - 1] + min(dp[i - 3], dp[i - 4]));
            }
        }
        return dp[dp.size() - 1] * 2 > std::accumulate(values.begin(), values.end(), 0);
    }
};

//@result Accepted Total Runtime: 8 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if (values.size() <= 2) {
            return true;
        }
        vector<pair<int, bool> > dp(values.size(), make_pair(INT_MIN, false));
        dp[values.size() - 1] = make_pair(values.back(), false);
        dp[values.size() - 2] = make_pair(values[values.size() - 2] + values.back(), true);
        for (size_t i = values.size() - 3; i < dp.size(); -- i) {
            int target = 0;
            // enemy takes one
            if (dp[i + 1].second) {
                target = values[i] + ((i + 3 < values.size()) ? dp[i + 3].first : 0);
            }
            // enemy takes two
            else {
                target = values[i] + ((i + 2 < values.size()) ? dp[i + 2].first : 0);
            }
            // I take one
            if (dp[i].first < target) {
                dp[i].first = target;
                dp[i].second = false;
            }
            if (dp[i + 2].second) {
                target = values[i] + values[i + 1] + ((i + 4 < values.size()) ? dp[i + 4].first : 0);
            }
            else {
                target = values[i] + values[i + 1] + ((i + 3 < values.size()) ? dp[i + 3].first : 0);
            }
            // I take two
            if (dp[i].first < target) {
                dp[i].first = target;
                dp[i].second = true;
            }
        }
        return dp[0].first > (dp[0].second ? dp[2].first : dp[1].first);
    }
};

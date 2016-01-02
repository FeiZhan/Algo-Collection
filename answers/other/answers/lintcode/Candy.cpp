//@result WA

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        vector<int> dp(ratings.size(), 0);
        for (size_t i = 0; i < dp.size(); ++ i) {
            if (0 == i || ratings[i] == ratings[i - 1]) {
                dp[i] = 1;
            }
            else if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = dp[i - 1] - 1;
            }
            if (ratings[i] < ratings[i - 1] && (ratings.size() == i + 1 || ratings[i] <= ratings[i + 1])) {
                int prev = dp[i];
                dp[i] = 1;
                size_t j = i - 1;
                for (; j < dp.size() && ratings[j] > ratings[j + 1]; -- j) {
                    prev = dp[j];
                    dp[j] = max(dp[j], dp[j + 1] + 1);
                }
            }
        }
        for (size_t i = 0; i < dp.size(); ++ i) {
            cout << "debug " << i << " " << dp[i] << endl;
        }
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        vector<int> dp(heights.size(), 0);
        for (size_t i = 0; i < heights.size(); ++ i) {
            dp[i] = i ? max(dp[i - 1], heights[i - 1]) : 0;
        }
        int trapped = 0;
        int max_height = 0;
        for (size_t i = heights.size() - 1; i < heights.size(); -- i) {
            if (i + 1 < heights.size()) {
                max_height = max(max_height, heights[i + 1]);
            }
            trapped += max(min(dp[i], max_height) - heights[i], 0);
        }
        return trapped;
    }
};

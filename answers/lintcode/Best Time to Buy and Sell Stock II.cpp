class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++ i) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        vector<int> local(prices.size(), 0);
        vector<int> forward(prices.size(), 0);
        for (size_t i = 1; i < prices.size(); ++ i) {
            local[i] = max(local[i - 1] + prices[i] - prices[i - 1], prices[i] - prices[i - 1]);
            forward[i] = max(forward[i - 1], local[i]);
        }
        fill(local.begin(), local.end(), 0);
        vector<int> backward(prices.size(), 0);
        for (size_t i = prices.size() - 2; i < prices.size(); -- i) {
            local[i] = max(local[i + 1] + prices[i + 1] - prices[i], prices[i + 1] - prices[i]);
            backward[i] = max(backward[i + 1], local[i]);
        }
        int max_profit = 0;
        for (size_t i = 1; i < prices.size(); ++ i) {
            max_profit = max(max_profit, forward[i] + backward[i]);
        }
        return max_profit;
    }
};

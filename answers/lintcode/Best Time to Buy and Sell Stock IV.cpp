class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        if (0 == prices.size()) {
            return 0;
        }
        else if (k >= prices.size()) {
            return maxProfit(prices);
        }
        vector<int> local(k + 1, 0);
        vector<int> global(k + 1, 0);
        for (size_t i = 0; i + 1 < prices.size(); ++ i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; -- j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
    int maxProfit(const vector<int> &prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++ i) {
            if (prices[i] - prices[i - 1] > 0) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

// cannot use DP - local-global, because it is not continuous

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int min_price = INT_MAX;
        int global = 0;
        for (size_t i = 0; i < prices.size(); ++ i) {
            min_price = min(min_price, prices[i]);
            global = max(global, prices[i] - min_price);
        }
        return global;
    }
};


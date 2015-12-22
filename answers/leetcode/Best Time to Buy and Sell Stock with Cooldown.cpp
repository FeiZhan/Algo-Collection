class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int pre_buy = 0;
        int sell = 0;
        int pre_sell = 0;
        for (size_t i = 0; i < prices.size(); ++ i) {
            pre_buy = buy;
            buy = max(buy, pre_sell - prices[i]);
            pre_sell = sell;
            sell = max(sell, pre_buy + prices[i]);
        }
        return sell;
    }
};

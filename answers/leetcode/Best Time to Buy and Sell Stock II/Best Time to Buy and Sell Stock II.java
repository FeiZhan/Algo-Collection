class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int profit = 0;
        int buy = prices[0];
        for (int price : prices) {
            if (price > buy) {
                profit += price - buy;
            }
            buy = price;
        }
        return profit;
    }
}
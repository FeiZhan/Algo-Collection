class Solution {
    public int maxProfit(int[] prices) {
        int sell0 = 0;
        int buy0 = 0;
        int sell = 0;
        int buy = Integer.MIN_VALUE;
        for (int price : prices) {
            buy0 = buy;
            buy = Math.max(buy0, sell0 - price);
            sell0 = sell;
            sell = Math.max(sell0, buy0 + price);
        }
        return sell;
    }
}
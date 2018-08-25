class Solution {
    public int maxProfit(int[] prices) {
        int buy0 = Integer.MAX_VALUE;
        int buy1 = Integer.MAX_VALUE;
        int sell0 = 0;
        int sell1 = 0;
        for (int price : prices) {
            buy0 = Math.min(buy0, price);
            sell0 = Math.max(sell0, price - buy0);
            buy1 = Math.min(buy1, price - sell0);
            sell1 = Math.max(sell1, price - buy1);
        }
        return sell1;
    }
}
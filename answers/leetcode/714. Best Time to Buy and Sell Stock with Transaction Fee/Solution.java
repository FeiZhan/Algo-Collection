class Solution {
    public int maxProfit(int[] prices, int fee) {
        int bought = Integer.MIN_VALUE;
        int sold = 0;
        for (int price : prices) {
            bought = Math.max(bought, sold - price);
            sold = Math.max(sold, bought + price - fee);
        }

        return sold;
    }
}
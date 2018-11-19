class Solution {
    public int maxProfit(int k, int[] prices) {
        if (k == 0) {
            return 0;
        } else if (k * 2 > prices.length) {
            int sum = 0;
            for (int i = 1; i < prices.length; i++) {
                if (prices[i] > prices[i - 1]) {
                    sum += prices[i] - prices[i - 1];
                }
            }
            return sum;
        } else {
            int[][] dp = new int[k][prices.length];
            for (int i = 0; i < k; i++) {
                int previous = Integer.MIN_VALUE;
                for (int j = 1; j < prices.length; j++) {
                    previous = Math.max(previous, (i > 0 ? dp[i - 1][j - 1] : 0) - prices[j - 1]);
                    dp[i][j] = Math.max(dp[i][j - 1], previous + prices[j]);
                }
            }
            return dp[k - 1][prices.length - 1];
        }
    }
}
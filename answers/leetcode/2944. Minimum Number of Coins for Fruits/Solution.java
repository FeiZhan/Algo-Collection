class Solution {
    public int minimumCoins(int[] prices) {
        int length = prices.length;
        int[] dp = new int[length];
        Arrays.fill(dp, Integer.MAX_VALUE);
        for (int i = 0; i < length; i++) {
            int price = prices[i];
            int buy = price + (i > 0 ? dp[i - 1] : 0);
            dp[i] = Math.min(dp[i], buy);
            //System.out.println(i + " " + price + ": " + dp[i]);
            for (int j = 1; j <= i + 1 && i + j < length; j++) {
                dp[i + j] = Math.min(dp[i + j], buy);
                //System.out.println(i + "+" + j + ": " + dp[i + j]);
            }
        }

        return dp[length - 1];
    }
}
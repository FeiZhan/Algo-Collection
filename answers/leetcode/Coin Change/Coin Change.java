class Solution {
    public int coinChange(int[] coins, int amount) {
        long[] dp = new long[amount + 1];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            if (dp[i] < Long.MAX_VALUE) {
                for (int j = 0; j < coins.length; j++) {
                    if ((long) i + (long) coins[j] <= (long) amount) {
                        dp[i + coins[j]] = Math.min(dp[i + coins[j]], dp[i] + 1l);
                    }
                }
            }
        }
        return (int) dp[amount];
    }
}
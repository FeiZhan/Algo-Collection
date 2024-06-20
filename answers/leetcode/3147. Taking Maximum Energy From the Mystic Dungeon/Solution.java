class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int result = Integer.MIN_VALUE;
        int[] dp = new int[energy.length];
        for (int i = energy.length - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < energy.length ? dp[i + k] : 0);
            result = Math.max(result, dp[i]);
        }

        return result;
    }
}
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        for (int i = 0; i <= target; i++) {
            for (int num : nums) {
                if (num == i) {
                    dp[i]++;
                }
                if (num < i && i - num < i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
}
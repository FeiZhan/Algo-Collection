class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        
        boolean[][] dp = new boolean[nums.length + 1][sum + 1];
        dp[0][0] = true;
        
        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = j == 0;
                } else {
                    dp[i][j] = dp[i - 1][j] || (j >= nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : false);
                }
            }
        }
        return dp[nums.length][sum];
    }
}
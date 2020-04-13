class Solution {
    public int maximumSum(int[] arr) {
        int[][] dp = new int[arr.length][2];
        dp[0][0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0] + arr[i], arr[i]);
        }
        dp[arr.length - 1][1] = arr[arr.length - 1];
        for (int i = arr.length - 2; i >= 0; i--) {
            dp[i][1] = Math.max(dp[i + 1][1] + arr[i], arr[i]);
        }
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            maxSum = Math.max(maxSum, dp[i][0]);
            if (arr.length > 1) {
                maxSum = Math.max(maxSum, (i > 0 ? dp[i - 1][0] : 0) + (i + 1 < arr.length ? dp[i + 1][1] : 0));
            }
        }
        return maxSum;
    }
}
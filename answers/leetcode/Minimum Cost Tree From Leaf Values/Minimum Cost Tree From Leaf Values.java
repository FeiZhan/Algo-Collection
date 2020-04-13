class Solution {
    public int mctFromLeafValues(int[] arr) {
        int[][] dp = new int[arr.length][arr.length];
        int[][] max = new int[arr.length][arr.length];
        for (int i = 0; i < arr.length; i++) {
            dp[i][i] = 0;
            max[i][i] = arr[i];
            if (i >= 1) {
                dp[i - 1][i] = arr[i - 1] * arr[i];
                max[i - 1][i] = Math.max(arr[i - 1], arr[i]);
            }
            for (int j = 2; i + j < arr.length; j++) {
                dp[i][i + j] = Integer.MAX_VALUE;
                max[i][i + j] = Integer.MIN_VALUE;
            }
        }
        for (int i = 2; i < arr.length; i++) {
            for (int j = 0; i + j < arr.length; j++) {
                for (int k = j; k < i + j; k++) {
                    dp[j][i + j] = Math.min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + max[j][k] * max[k + 1][i + j]);
                    max[j][i + j] = Math.max(max[j][i + j], arr[k]);
                }
                max[j][i + j] = Math.max(max[j][i + j], arr[i + j]);
                System.out.println(j + " " + (i + j) + ": " + dp[j][i + j] + " " + max[j][i + j]);
            }
        }
        return dp[0][arr.length - 1];
    }
}
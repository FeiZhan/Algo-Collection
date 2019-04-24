class Solution {
    public int minFallingPathSum(int[][] A) {
        int[][] dp = new int[A.length][A[0].length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                dp[i][j] = A[i][j];
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                    if (j > 0) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + A[i][j]);
                    }
                    if (j + 1 < A[i].length) {
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1] + A[i][j]);
                    }
                }
            }
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < A[0].length; i++) {
            result = Math.min(result, dp[A.length - 1][i]);
        }
        return result;
    }
}
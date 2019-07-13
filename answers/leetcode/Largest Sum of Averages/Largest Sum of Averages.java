class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        double sum = 0;
        double[][] dp = new double[K][A.length];
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            dp[0][i] = sum / (i + 1);
        }
        for (int i = 1; i < K; i++) {
            for (int j = 0; j < A.length; j++) {
                sum = 0;
                for (int k = j; k >= 1; k--) {
                    sum += A[k];
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][k - 1] + sum / (j - k + 1));
                }
            }
        }
        return dp[K - 1][A.length - 1];
    }
}
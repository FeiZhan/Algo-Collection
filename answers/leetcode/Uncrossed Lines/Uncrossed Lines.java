class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int[][] dp = new int[A.length][B.length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                if (i > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                }
                if (j > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                }
                if (A[i] == B[j]) {
                    dp[i][j] = Math.max(dp[i][j], 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0));
                }
            }
        }
        return dp[A.length - 1][B.length - 1];
    }
}
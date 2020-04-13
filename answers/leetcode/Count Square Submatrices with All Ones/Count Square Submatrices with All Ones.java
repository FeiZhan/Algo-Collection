class Solution {
    public int countSquares(int[][] matrix) {
        int sum = 0;
        int[][] dp = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                }
                sum += dp[i][j];
                System.out.println(i + " " + j + ": " + dp[i][j] + " " + sum);
            }
        }
        return sum;
    }
}
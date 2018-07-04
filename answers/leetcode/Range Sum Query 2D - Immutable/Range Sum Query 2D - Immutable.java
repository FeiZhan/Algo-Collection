class NumMatrix {
    
    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        this.dp = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                this.dp[i][j] = matrix[i][j] + (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0)
                    - (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return this.dp[row2][col2] - (row1 > 0 ? this.dp[row1 - 1][col2] : 0) - (col1 > 0 ? this.dp[row2][col1 - 1] : 0)
            + (row1 > 0 && col1 > 0 ? this.dp[row1 - 1][col1 - 1] : 0);
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
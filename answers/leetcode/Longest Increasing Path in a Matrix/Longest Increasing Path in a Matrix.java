class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        int[][] dp = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                this.dfs(1, i, j, dp, matrix);
            }
        }
        int longest = 0;
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                longest = Math.max(longest, dp[i][j]);
            }
        }
        return longest;
    }

    private void dfs(int distance, int x, int y, int[][] dp, int[][] matrix) {
        if (distance <= dp[x][y]) {
            return;
        }

        dp[x][y] = distance;
        if (x > 0 && matrix[x][y] < matrix[x - 1][y]) {
            this.dfs(distance + 1, x - 1, y, dp, matrix);
        }
        if (x + 1 < matrix.length && matrix[x][y] < matrix[x + 1][y]) {
            this.dfs(distance + 1, x + 1, y, dp, matrix);
        }
        if (y > 0 && matrix[x][y] < matrix[x][y - 1]) {
            this.dfs(distance + 1, x, y - 1, dp, matrix);
        }
        if (y + 1 < matrix[x].length && matrix[x][y] < matrix[x][y + 1]) {
            this.dfs(distance + 1, x, y + 1, dp, matrix);
        }
    }
}
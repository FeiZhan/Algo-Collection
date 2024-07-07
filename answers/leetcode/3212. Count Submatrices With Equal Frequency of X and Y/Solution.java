class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int result = 0;
        boolean[][] haveX = new boolean[height][width];
        int[][] dp = new int[height][width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char cell = grid[i][j];
                int value = cell == 'X' ? 1 : cell == 'Y' ? -1 : 0;
                haveX[i][j] = value == 1 || (i > 0 && haveX[i - 1][j]) || (j > 0 && haveX[i][j - 1]);
                dp[i][j] = value + (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0) - (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                result += haveX[i][j] && dp[i][j] == 0 ? 1 : 0;
            }
        }

        return result;
    }
}
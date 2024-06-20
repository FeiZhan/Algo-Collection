class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int height = grid.size();
        int width = grid.get(0).size();
        int result = Integer.MIN_VALUE;
        int[][] dp = new int[height][width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int cell = grid.get(i).get(j);
                if (i == 0 && j == 0) {
                    dp[i][j] = cell;
                } else if (i == 0) {
                    dp[i][j] = Math.min(dp[i][j - 1], cell);
                    result = Math.max(result, cell - dp[i][j - 1]);
                } else if (j == 0) {
                    dp[i][j] = Math.min(dp[i - 1][j], cell);
                    result = Math.max(result, cell - dp[i - 1][j]);
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = Math.min(dp[i][j], cell);
                    result = Math.max(result, cell - dp[i][j - 1]);
                    result = Math.max(result, cell - dp[i - 1][j]);
                }
            }
        }

        return result;
    }
}
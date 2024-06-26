class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int height = grid.length;
        int width = grid[0].length;
        int result = 0;
        int[][] sums = new int[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                sums[i][j] = grid[i][j] + (i > 0 ? sums[i - 1][j] : 0) + (j > 0 ? sums[i][j - 1] : 0) - (i > 0 && j > 0 ? sums[i - 1][j - 1] : 0);
                result += sums[i][j] <= k ? 1 : 0;
            }
        }

        return result;
    }
}
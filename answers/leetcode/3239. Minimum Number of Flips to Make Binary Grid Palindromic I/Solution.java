class Solution {
    public int minFlips(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int rowCount = 0;
        for (int[] row : grid) {
            for (int i = 0; i + i < width; i++) {
                rowCount += row[i] != row[width - i - 1] ? 1 : 0;
            }
        }
        int columnCount = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j + j < height; j++) {
                columnCount += grid[j][i] != grid[height - j - 1][i] ? 1 : 0;
            }
        }

        return Math.min(rowCount, columnCount);
    }
}
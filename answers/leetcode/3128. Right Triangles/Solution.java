class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int[] rowCounts = new int[height];
        int[] columnCounts = new int[width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                rowCounts[i] += grid[i][j];
                columnCounts[j] += grid[i][j];
            }
        }

        long result = 0l;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] > 0) {
                    result += ((long)rowCounts[i] - 1l) * ((long)columnCounts[j] - 1l);
                }
            }
        }

        return result;
    }
}
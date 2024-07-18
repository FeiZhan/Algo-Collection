class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int[] rows = new int[height];
        int[] columns = new int[width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                switch (grid[i][j]) {
                    case 0:
                        rows[i]--;
                        columns[j]--;
                        break;
                    case 1:
                        rows[i]++;
                        columns[j]++;
                        break;
                }
            }
        }

        int[][] result = new int[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                result[i][j] = rows[i] + columns[j];
            }
        }

        return result;
    }
}
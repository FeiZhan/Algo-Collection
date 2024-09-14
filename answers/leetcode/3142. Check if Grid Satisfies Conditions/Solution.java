class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        for (int i = 0; i < width; i++) {
            int value = grid[0][i];
            for (int j = 0; j < height; j++) {
                if (grid[j][i] != value) {
                    return false;
                }
            }
        }

        for (int i = 1; i < width; i++) {
            if (grid[0][i - 1] == grid[0][i]) {
                return false;
            }
        }

        return true;
    }
}
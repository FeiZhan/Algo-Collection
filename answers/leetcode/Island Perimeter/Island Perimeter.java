class Solution {
    public int islandPerimeter(int[][] grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    if (0 == i || grid[i - 1][j] == 0) {
                        perimeter++;
                    }
                    if (grid.length == i + 1 || grid[i + 1][j] == 0) {
                        perimeter++;
                    }
                    if (0 == j || grid[i][j - 1] == 0) {
                        perimeter++;
                    }
                    if (grid[i].length == j + 1 || grid[i][j + 1] == 0) {
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
}
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        if (grid[r0][c0] != color) {
            int[][] flag = new int[grid.length][grid[0].length];
            this.dfs(flag, grid, r0, c0, grid[r0][c0]);
            for (int i = 0; i < flag.length; i++) {
                for (int j = 0; j < flag[i].length; j++) {
                    if (flag[i][j] == 2) {
                        grid[i][j] = color;
                    }
                }
            }
        }
        return grid;
    }

    private void dfs(int[][] flag, int[][] grid, int row, int column, int color) {
        if (row < 0 || row >= grid.length || column < 0 || column >= grid[row].length
            || flag[row][column] != 0 || grid[row][column] != color) {
            return;
        } else if (row == 0 || row + 1 == grid.length || column == 0 || column + 1 == grid[row].length) {
            flag[row][column] = 2;
        } else if (grid[row][column] != grid[row - 1][column] || grid[row][column] != grid[row + 1][column]
            || grid[row][column] != grid[row][column - 1] || grid[row][column] != grid[row][column + 1]) {
            flag[row][column] = 2;
        } else {
            flag[row][column] = 1;
        }
        this.dfs(flag, grid, row - 1, column, color);
        this.dfs(flag, grid, row + 1, column, color);
        this.dfs(flag, grid, row, column - 1, color);
        this.dfs(flag, grid, row, column + 1, color);
    }
}
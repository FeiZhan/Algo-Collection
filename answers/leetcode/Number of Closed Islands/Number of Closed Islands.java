class Solution {
    public int closedIsland(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            if (grid[i][0] == 0) {
                this.fill(i, 0, grid);
            }
            if (grid[i][grid[i].length - 1] == 0) {
                this.fill(i, grid[i].length - 1, grid);
            }
        }
        for (int i = 0; i < grid[0].length; i++) {
            if (grid[0][i] == 0) {
                this.fill(0, i, grid);
            }
            if (grid[grid.length - 1][i] == 0) {
                this.fill(grid.length - 1, i, grid);
            }
        }
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    this.fill(i, j, grid);
                }
            }
        }
        return count;
    }

    private void fill(int x, int y, int[][] grid) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] != 0) {
            return;
        }
        grid[x][y] = 1;
        this.fill(x - 1, y, grid);
        this.fill(x + 1, y, grid);
        this.fill(x, y - 1, grid);
        this.fill(x, y + 1, grid);
    }
}
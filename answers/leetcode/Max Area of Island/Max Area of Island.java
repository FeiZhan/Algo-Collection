class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                maxArea = Math.max(maxArea, this.dfs(grid, i, j));
            }
        }
        return maxArea;
    }

    private int dfs(int[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] != 1) {
            return 0;
        }
        grid[x][y] = 2;
        return 1 + dfs(grid, x - 1, y) + dfs(grid, x + 1, y) + dfs(grid, x, y - 1) + dfs(grid, x, y + 1);
    }
}
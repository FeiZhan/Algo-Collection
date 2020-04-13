class Solution {
    public int getMaximumGold(int[][] grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                maxGold = Math.max(maxGold, this.dfs(i, j, grid));
            }
        }
        return maxGold;
    }

    private int dfs(int x, int y, int[][] grid) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] == 0) {
            return 0;
        }
        int temp = grid[x][y];
        grid[x][y] = 0;
        int maxGold = 0;
        maxGold = Math.max(maxGold, this.dfs(x - 1, y, grid));
        maxGold = Math.max(maxGold, this.dfs(x + 1, y, grid));
        maxGold = Math.max(maxGold, this.dfs(x, y - 1, grid));
        maxGold = Math.max(maxGold, this.dfs(x, y + 1, grid));
        grid[x][y] = temp;
        return maxGold + grid[x][y];
    }
}
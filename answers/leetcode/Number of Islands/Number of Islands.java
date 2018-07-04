class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    this.dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    
    private void dfs(char[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '2';
        this.dfs(grid, x - 1, y);
        this.dfs(grid, x + 1, y);
        this.dfs(grid, x, y - 1);
        this.dfs(grid, x, y + 1);
    }
}
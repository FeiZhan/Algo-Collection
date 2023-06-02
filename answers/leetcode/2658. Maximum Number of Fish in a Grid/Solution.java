class Solution {
    public int findMaxFish(int[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int maxFish = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int fish = dfs(i, j, visited, grid);
                maxFish = Math.max(maxFish, fish);
            }
        }

        return maxFish;
    }

    private int dfs(int x, int y, boolean[][] visited, int[][] grid) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || visited[x][y] || grid[x][y] == 0) {
            return 0;
        }

        visited[x][y] = true;
        int fish = grid[x][y];
        fish += dfs(x - 1, y, visited, grid);
        fish += dfs(x + 1, y, visited, grid);
        fish += dfs(x, y - 1, visited, grid);
        fish += dfs(x, y + 1, visited, grid);

        return fish;
    }
}
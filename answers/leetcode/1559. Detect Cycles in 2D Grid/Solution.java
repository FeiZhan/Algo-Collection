class Solution {
    public boolean containsCycle(char[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (dfs(i, j, 0, grid[i][j], grid)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(int x, int y, int direction, char target, char[][] grid) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length) {
            return false;
        }

        char c = grid[x][y];
        if (Character.isUpperCase(c)) {
            return Character.toLowerCase(c) == target;
        } else {
            if (c != target) {
                return false;
            }
        }
        grid[x][y] = Character.toUpperCase(c);
        if (direction != 1 && dfs(x + 1, y, 2, target, grid)) {
            return true;
        }
        if (direction != 2 && dfs(x - 1, y, 1, target, grid)) {
            return true;
        }
        if (direction != 3 && dfs(x, y + 1, 4, target, grid)) {
            return true;
        }
        if (direction != 4 && dfs(x, y - 1, 3, target, grid)) {
            return true;
        }
        return false;
    }
}
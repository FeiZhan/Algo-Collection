class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                int black = (grid[i - 1][j - 1] == 'B' ? 1 : 0) + (grid[i - 1][j] == 'B' ? 1 : 0) + (grid[i][j - 1] == 'B' ? 1 : 0) + (grid[i][j] == 'B' ? 1 : 0);
                if (black != 2) {
                    return true;
                }
            }
        }

        return false;
    }
}
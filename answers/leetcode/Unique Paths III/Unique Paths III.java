class Solution {
    public int uniquePathsIII(int[][] grid) {
        int count = 0;
        int[] start = new int[2];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                count += grid[i][j] == 0 ? 1 : 0;
                if (grid[i][j] == 1) {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }
        return this.dfs(start, count + 1, grid);
    }

    private int dfs(final int[] start, int count, final int[][] grid) {
        if (count < 0 || start[0] < 0 || start[0] >= grid.length || start[1] < 0 || start[1] >= grid[start[0]].length) {
            return 0;
        }

        int cell = grid[start[0]][start[1]];
        //System.out.println(start[0] + " " + start[1] + ": " + cell + " " + count);
        if (cell == 2 && count == 0) {
            return 1;
        }
        if (cell != 0 && cell != 1) {
            return 0;
        }

        grid[start[0]][start[1]] = -2;
        int result = this.dfs(new int[]{start[0] - 1, start[1]}, count - 1, grid)
            + this.dfs(new int[]{start[0] + 1, start[1]}, count - 1, grid)
            + this.dfs(new int[]{start[0], start[1] - 1}, count - 1, grid)
            + this.dfs(new int[]{start[0], start[1] + 1}, count - 1, grid);
        grid[start[0]][start[1]] = cell;
        return result;
    }
}
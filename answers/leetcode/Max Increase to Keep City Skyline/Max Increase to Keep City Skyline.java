class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] column = new int[grid.length];
        int[] row = new int[grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                column[i] = Math.max(column[i], grid[i][j]);
                row[j] = Math.max(row[j], grid[i][j]);
            }
        }
        int sum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                sum += Math.min(column[i], row[j]) - grid[i][j];
            }
        }
        return sum;
    }
}
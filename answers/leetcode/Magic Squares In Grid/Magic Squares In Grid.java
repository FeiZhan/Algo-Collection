class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int count = 0;
        for (int i = 2; i < grid.length; i++) {
            for (int j = 2; j < grid[i].length; j++) {
                int max = Integer.MIN_VALUE;
                int min = Integer.MAX_VALUE;
                Set<Integer> numbers = new HashSet<>();
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        max = Math.max(max, grid[i - m][j - n]);
                        min = Math.min(min, grid[i - m][j - n]);
                        numbers.add(grid[i - m][j - n]);
                    }
                }
                if (max == 9 && min == 1 && numbers.size() == 9
                    && grid[i - 2][j - 2] + grid[i - 1][j - 2] + grid[i][j - 2] == 15
                    && grid[i - 2][j - 1] + grid[i - 1][j - 1] + grid[i][j - 1] == 15
                    && grid[i - 2][j] + grid[i - 1][j] + grid[i][j] == 15
                    && grid[i - 2][j - 2] + grid[i - 2][j - 1] + grid[i - 2][j] == 15
                    && grid[i - 1][j - 2] + grid[i - 1][j - 1] + grid[i - 1][j] == 15
                    && grid[i][j - 2] + grid[i][j - 1] + grid[i][j] == 15
                    && grid[i - 2][j - 2] + grid[i - 1][j - 1] + grid[i][j] == 15
                    && grid[i][j - 2] + grid[i - 1][j - 1] + grid[i - 2][j] == 15) {
                        count++;
                    }
            }
        }
        return count;
    }
}
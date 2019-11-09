class Solution {
    public int projectionArea(int[][] grid) {
        int sum = 0;
        int[] left = new int[grid.length];
        int[] top = new int[grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] > 0) {
                    sum++;
                    left[i] = Math.max(left[i], grid[i][j]);
                    top[j] = Math.max(top[j], grid[i][j]);
                }
            }
        }
        for (int num : left) {
            sum += num;
        }
        for (int num : top) {
            sum += num;
        }
        return sum;
    }
}
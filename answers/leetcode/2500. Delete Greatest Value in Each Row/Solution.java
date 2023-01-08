class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int sum = 0;

        for (int i = 0; i < width; i++) {
            int max = 0;
            for (int j = 0; j < height; j++) {
                int max1 = 0;
                for (int k = 0; k < width; k++) {
                    max1 = Math.max(max1, grid[j][k]);
                }
                max = Math.max(max, max1);
                for (int k = 0; k < width; k++) {
                    if (grid[j][k] == max1) {
                        grid[j][k] = 0;
                        break;
                    }
                }
            }
            sum += max;
        }

        return sum;
    }
}
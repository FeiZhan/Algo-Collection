class Solution {
    public int minimumArea(int[][] grid) {
        int top = Integer.MAX_VALUE;
        int bottom = 0;
        int left = Integer.MAX_VALUE;
        int right = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] != 0) {
                    top = Math.min(top, i);
                    bottom = Math.max(bottom, i);
                    left = Math.min(left, j);
                    right = Math.max(right, j);
                }
            }
        }

        return (bottom - top + 1) * (right - left + 1);
    }
}
class Solution {
    public int countNegatives(int[][] grid) {
        int count = 0;
        int left = 0;
        int right = grid[0].length - 1;
        for (int i = 0; i < grid.length; i++) {
            while (left <= right) {
                int middle = (left + right) / 2;
                int number = grid[i][middle];
                if (number < 0 && (middle == 0 || grid[i][middle - 1] >= 0)) {
                    count += grid[i].length - middle;
                    left = 0;
                    right = middle;
                    break;
                } else if (number >= 0) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
            left = 0;
            right = grid[i].length - 1;
        }
        return count;
    }
}
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int x = 0;
        int y = matrix[0].length - 1;
        while (x < matrix.length && y >= 0) {
            if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                return true;
            }
        }
        return false;
    }
}
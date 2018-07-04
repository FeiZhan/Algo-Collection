class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int row = 0;
        int left = 0;
        int right = matrix.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (matrix[middle][0] == target) {
                return true;
            } else if (matrix[middle][0] > target) {
                right--;
            } else if (matrix[middle][0] < target && middle + 1 < matrix.length && matrix[middle + 1][0] <= target) {
                left++;
            } else {
                row = middle;
                break;
            }
        }
        left = 0;
        right = matrix[row].length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            int value = matrix[row][middle];
            if (value > target) {
                right--;
            } else if (value < target) {
                left++;
            } else {
                return true;
            }
        }
        return false;
    }
}
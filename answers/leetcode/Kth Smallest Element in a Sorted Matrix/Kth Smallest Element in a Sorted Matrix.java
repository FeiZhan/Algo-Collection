class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int length = matrix.length;
        int low = matrix[0][0];
        int high = matrix[length - 1][length - 1];
        while (low <= high) {
            int middle = low + (high - low) / 2;
            int count = this.getLess(middle, matrix);
            if (count < k) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return low;
    }

    private int getLess(int value, int[][] matrix) {
        int result = 0;
        int i = matrix.length - 1;
        int j = 0;
        while (i >= 0 && j < matrix.length) {
            if (matrix[i][j] > value) {
                i--;
            } else {
                result += i + 1;
                j++;
            }
        }
        return result;
    }
}
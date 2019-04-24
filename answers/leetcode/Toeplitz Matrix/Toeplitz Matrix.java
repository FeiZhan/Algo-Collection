class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 1; i + j < matrix.length && j < matrix[i].length; j++) {
                if (matrix[i + j][j] != matrix[i + j - 1][j - 1]) {
                    return false;
                }
            }
        }
        for (int i = 0; i < matrix[0].length; i++) {
            for (int j = 1; i + j < matrix[0].length && j < matrix.length; j++) {
                if (matrix[j][i + j] != matrix[j - 1][i + j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
}
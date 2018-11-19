class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        if (n == 0) {
            return matrix;
        }
        int num = 0;
        int rowStart = 0;
        int rowEnd = n - 1;
        int columnStart = 0;
        int columnEnd = n - 1;
        while (rowStart <= rowEnd && columnStart <= columnEnd) {
            for (int i = columnStart; i <= columnEnd; i++) {
                matrix[rowStart][i] = ++num;
            }
            rowStart++;
            for (int i = rowStart; i <= rowEnd; i++) {
                matrix[i][columnEnd] = ++num;
            }
            columnEnd--;
            if (rowStart <= rowEnd) {
                for (int i = columnEnd; i >= columnStart; i--) {
                    matrix[rowEnd][i] = ++num;
                }
                rowEnd--;
            }
            if (columnStart <= columnEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    matrix[i][columnStart] = ++num;
                }
                columnStart++;
            }
        }
        return matrix;
    }
}
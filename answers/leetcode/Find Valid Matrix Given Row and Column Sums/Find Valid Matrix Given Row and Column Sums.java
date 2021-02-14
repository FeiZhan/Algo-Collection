class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int columnLength = colSum.length;
        int rowLength = rowSum.length;
        int[][] result = new int[rowLength][columnLength];

        while (true) {
            int columnIndex = -1;
            for (int i = 0; i < columnLength; i++) {
                if (colSum[i] > 0 && (columnIndex < 0 || colSum[i] < colSum[columnIndex])) {
                    columnIndex = i;
                }
            }
            if (columnIndex < 0) {
                break;
            }

            int rowIndex = -1;
            for (int i = 0; i < rowLength; i++) {
                if (rowSum[i] > 0 && (rowIndex < 0 || rowSum[i] < rowSum[rowIndex])) {
                    rowIndex = i;
                }
            }
            if (rowIndex < 0) {
                break;
            }

            result[rowIndex][columnIndex] = Math.min(colSum[columnIndex], rowSum[rowIndex]);
            colSum[columnIndex] -= result[rowIndex][columnIndex];
            rowSum[rowIndex] -= result[rowIndex][columnIndex];
        }
        return result;
    }
}
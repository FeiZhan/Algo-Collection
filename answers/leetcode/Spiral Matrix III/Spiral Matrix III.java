class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int column = c0;
        int length = 3;
        int row = r0;
        int size = R * C;
        int[][] result = new int[size][2];
        this.add(result, row, column, 0, R, C);
        for (int i = 1; i < size;) {
            column++;
            i += this.add(result, row, column, i, R, C);
            for (int j = 2; j < length; j++) {
                row++;
                i += this.add(result, row, column, i, R, C);
            }
            for (int j = 1; j < length; j++) {
                column--;
                i += this.add(result, row, column, i, R, C);
            }
            for (int j = 1; j < length; j++) {
                row--;
                i += this.add(result, row, column, i, R, C);
            }
            for (int j = 1; j < length; j++) {
                column++;
                i += this.add(result, row, column, i, R, C);
            }
            length += 2;
        }
        return result;
    }

    private int add(int[][] result, int row, int column, int index, int maxRow, int maxColumn) {
        if (row >= 0 && row < maxRow && column >= 0 && column < maxColumn) {
            result[index][0] = row;
            result[index][1] = column;
            return 1;
        }
        return 0;
    }
}
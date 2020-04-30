class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int[] columns = new int[matrix[0].length];
        int[] rows = new int[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            rows[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < matrix[0].length; i++) {
            columns[i] = Integer.MIN_VALUE;
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                columns[j] = Math.max(columns[j], matrix[i][j]);
                rows[i] = Math.min(rows[i], matrix[i][j]);
            }
        }
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == columns[j] && matrix[i][j] == rows[i]) {
                    result.add(matrix[i][j]);
                }
            }
        }
        return result;
    }
}
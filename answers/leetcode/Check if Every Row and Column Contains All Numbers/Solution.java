class Solution {
    public boolean checkValid(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return true;
        } else if (matrix.length != matrix[0].length) {
            return false;
        }

        int length = matrix.length;
        for (int i = 0; i < length; i++) {
            Set<Integer> columnSet = new HashSet<>();
            Set<Integer> rowSet = new HashSet<>();
            for (int j = 0; j < length; j++) {
                columnSet.add(matrix[j][i]);
                rowSet.add(matrix[i][j]);
            }
            if (columnSet.size() != length || rowSet.size() != length) {
                return false;
            }
        }

        return true;
    }
}
//Runtime: 69 ms, faster than 28.04% of Java online submissions for Check if Every Row and Column Contains All Numbers.
//Memory Usage: 92.9 MB, less than 46.29% of Java online submissions for Check if Every Row and Column Contains All Numbers.

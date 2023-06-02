class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        Map<Integer, Integer> indexes = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            indexes.put(arr[i], i);
        }

        Map<Integer, Integer> rows = new HashMap<>();
        Map<Integer, Integer> columns = new HashMap<>();
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                int index = indexes.get(mat[i][j]);
                rows.put(index, i);
                columns.put(index, j);
            }
        }

        Map<Integer, Integer> rowCounts = new HashMap<>();
        Map<Integer, Integer> columnCounts = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            int row = rows.get(i);
            rowCounts.put(row, rowCounts.getOrDefault(row, 0) + 1);
            int column = columns.get(i);
            columnCounts.put(column, columnCounts.getOrDefault(column, 0) + 1);
            //System.out.println(i + " " + arr[i] + " " + rowCounts.get(row) + " " + columnCounts.get(column));
            if (rowCounts.get(row) == mat[row].length || columnCounts.get(column) == mat.length) {
                return i;
            }
        }

        return -1;
    }
}
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[] rows = new int[n];
        int[] columns = new int[m];
        for (int[] index : indices) {
            rows[index[0]]++;
            columns[index[1]]++;
        }
        int count = 0;
        for (int row : rows) {
            for (int column : columns) {
                count += (row + column) % 2;
            }
        }
        return count;
    }
}
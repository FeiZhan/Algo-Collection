class Solution {
    public int numSpecial(int[][] mat) {
        int[] rows = new int[mat.length];
        int[] columns = new int[mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                rows[i] += mat[i][j];
                columns[j] += mat[i][j];
            }
        }
        int count = 0;
        for (int i = 0; i < rows.length; i++) {
            if (rows[i] == 1) {
                for (int j = 0; j < columns.length; j++) {
                    if (mat[i][j] == 1 && columns[j] == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        for (int i = 0; i < mat.length && i < mat[i].length; i++) {
            sum += mat[i][i] + mat[i][mat.length - 1 - i];
        }
        if (mat.length % 2 == 1) {
            sum -= mat[mat.length / 2][mat.length / 2];
        }
        return sum;
    }
}
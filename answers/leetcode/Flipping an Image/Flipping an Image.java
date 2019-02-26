class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j * 2 < A[i].length; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][A[i].length - j - 1];
                A[i][A[i].length - j - 1] = temp;
            }
            for (int j = 0; j < A[i].length; j++) {
                A[i][j] = A[i][j] == 0 ? 1 : 0;
            }
        }
        return A;
    }
}
class Solution {
    public int matrixScore(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < A[i].length; j++) {
                    A[i][j] ^= 1;
                }
            }
        }
        for (int i = 1; i < A[0].length; i++) {
            int count = 0;
            for (int j = 0; j < A.length; j++) {
                count += A[j][i];
            }
            if (count * 2 < A.length) {
                for (int j = 0; j < A.length; j++) {
                    A[j][i] ^= 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            int number = 0;
            for (int j = 0; j < A[i].length; j++) {
                number = (number << 1) + A[i][j];
            }
            sum += number;
        }
        return sum;
    }
}
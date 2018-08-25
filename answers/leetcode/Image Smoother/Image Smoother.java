class Solution {
    public int[][] imageSmoother(int[][] M) {
        int[][] smoothed = new int[M.length][M[0].length];
        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[i].length; j++) {
                int sum = M[i][j];
                int count = 1;
                if (i > 0) {
                    sum += M[i - 1][j];
                    count++;
                    if (j > 0) {
                        sum += M[i - 1][j - 1];
                        count++;
                    }
                    if (j + 1 < M[i].length) {
                        sum += M[i - 1][j +1];
                        count++;
                    }
                }
                if (i + 1 < M.length) {
                    sum += M[i + 1][j];
                    count++;
                    if (j > 0) {
                        sum += M[i + 1][j - 1];
                        count++;
                    }
                    if (j + 1 < M[i].length) {
                        sum += M[i + 1][j +1];
                        count++;
                    }
                }
                if (j > 0) {
                    sum += M[i][j - 1];
                    count++;
                }
                if (j + 1 < M[i].length) {
                    sum += M[i][j +1];
                    count++;
                }
                smoothed[i][j] = sum / count;
            }
        }
        return smoothed;
    }
}
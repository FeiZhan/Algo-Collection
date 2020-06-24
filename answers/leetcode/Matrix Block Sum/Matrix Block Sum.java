class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int height = mat.length;
        int width = mat[0].length;
        int[][] sums = new int[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                sums[i][j] = mat[i][j]
                    + (i > 0 ? sums[i - 1][j] : 0)
                    + (j > 0 ? sums[i][j - 1] : 0)
                    - (i > 0 && j > 0 ? sums[i - 1][j - 1] : 0);
            }
        }
        int[][] result = new int[height][mat[0].length];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int bottom = Math.min(i + K, height - 1);
                int right = Math.min(j + K, width - 1);
                result[i][j] = sums[bottom][right]
                    - (i > K ? sums[i - K - 1][right] : 0)
                    - (j > K ? sums[bottom][j - K - 1] : 0)
                    + (i > K && j > K ? sums[i - K - 1][j - K - 1] : 0);
                //System.out.println(i + " " + j + " " + bottom + " " + right + " " + result[i][j]);
            }
        }
        return result;
    }
}
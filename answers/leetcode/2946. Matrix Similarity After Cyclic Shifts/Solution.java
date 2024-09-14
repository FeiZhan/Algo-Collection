class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int height = mat.length;
        int width = mat[0].length;
        k %= width;
        int[][] shifted = new int[height][width];
        for (int i = 0; i < height; i += 2) {
            for (int j = 0; j < k; j++) {
                shifted[i][width - k + j] = mat[i][j];
            }
            for (int j = k; j < width; j++) {
                shifted[i][j - k] = mat[i][j];
            }
        }
        for (int i = 1; i < height; i += 2) {
            for (int j = 0; j < k; j++) {
                shifted[i][j] = mat[i][width - k + j];
            }
            for (int j = k; j < width; j++) {
                shifted[i][j] = mat[i][j - k];
            }
        }
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (mat[i][j] != shifted[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
}
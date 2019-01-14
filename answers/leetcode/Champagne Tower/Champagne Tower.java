class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] glasses = new double[200][200];
        glasses[0][0] = (double) poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double excess = (glasses[i][j] - 1.) / 2.;
                if (excess > 0) {
                    glasses[i + 1][j] += excess;
                    glasses[i + 1][j + 1] += excess;
                }
            }
        }
        return Math.min(glasses[query_row][query_glass], 1.);
    }
}
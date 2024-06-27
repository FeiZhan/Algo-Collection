class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        int[][] distances = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(distances[i], Integer.MAX_VALUE);
            distances[i][i] = 0;
        }
        for (int i = 1; i < n; i++) {
            distances[i - 1][i] = 1;
            distances[i][i - 1] = 1;
        }
        distances[x - 1][y - 1] = 1;
        distances[y - 1][x - 1] = 1;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (distances[i][k] < Integer.MAX_VALUE && distances[k][j] < Integer.MAX_VALUE) {
                        distances[i][j] = Math.min(distances[i][j], distances[i][k] + distances[k][j]);
                        distances[j][i] = distances[i][j];
                    }
                    //System.out.println(i + " " + j + " " + k + ":" + distances[i][k] + " " +  + distances[k][j] + "-" + distances[i][j]);
                }
            }
        }

        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                //System.out.println(i + " " + j + ":" + distances[i][j] + " " +  + distances[j][i]);
                if (distances[i][j] <= n) {
                    result[distances[i][j] - 1] += 2;
                }
            }
        }

        return result;
    }
}
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] results = new int[R * C][2];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                results[i * C + j][0] = i;
                results[i * C + j][1] = j;
            }
        }
        Arrays.sort(results, (p1, p2) -> {
            int d1 = Math.abs(p1[0] - r0) + Math.abs(p1[1] - c0);
            int d2 = Math.abs(p2[0] - r0) + Math.abs(p2[1] - c0);
            return d1 - d2;
        });
        return results;
    }
}
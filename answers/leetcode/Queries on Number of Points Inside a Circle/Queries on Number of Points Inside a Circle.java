class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            for (int j = 0; j < points.length; j++) {
                int distanceX = queries[i][0] - points[j][0];
                int distanceY = queries[i][1] - points[j][1];
                if (distanceX * distanceX + distanceY * distanceY <= queries[i][2] * queries[i][2]) {
                    result[i]++;
                }
            }
        }
        return result;
    }
}
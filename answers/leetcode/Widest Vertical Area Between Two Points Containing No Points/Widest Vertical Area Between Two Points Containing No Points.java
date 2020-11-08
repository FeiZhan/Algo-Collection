class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (p0, p1) -> p0[0] - p1[0]);
        int max = 0;
        for (int i = 1; i < points.length; i++) {
            max = Math.max(max, points[i][0] - points[i - 1][0]);
        }
        return max;
    }
}
class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        Arrays.sort(points, Comparator.comparingInt(point -> point[0]));
        int start = -1;
        int result = 0;
        for (int[] point : points) {
            if (start == -1) {
                start = point[0];
            }
            if (point[0] - start > w) {
                result++;
                start = point[0];
            }
        }

        return result + (start != -1 ? 1 : 0);
    }
}
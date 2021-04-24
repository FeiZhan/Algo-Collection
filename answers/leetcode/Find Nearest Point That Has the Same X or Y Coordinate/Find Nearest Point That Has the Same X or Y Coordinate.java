class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int nearestIndex = -1;

        for (int i = 0; i < points.length; i++) {
            int[] point = points[i];
            if (point[0] == x || point[1] == y) {
                if (nearestIndex < 0) {
                    nearestIndex = i;
                } else if (Math.abs(point[0] - x) + Math.abs(point[1] - y)
                    < Math.abs(points[nearestIndex][0] - x) + Math.abs(points[nearestIndex][1] - y)) {
                    nearestIndex = i;
                }
            }
        }

        return nearestIndex;
    }
}
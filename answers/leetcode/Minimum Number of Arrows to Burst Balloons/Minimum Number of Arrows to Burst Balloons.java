class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        int count = 0;
        int end = Integer.MIN_VALUE;
        for (int[] point : points) {
            end = Math.min(end, point[1]);
            if (point[0] > end) {
                //System.out.println(count + " " + end + " " + point[0] + " " + point[1]);
                count++;
                end = point[1];
            }
        }
        if (points.length > 0 && count == 0) {
            count = 1;
        }
        return count;
    }
}
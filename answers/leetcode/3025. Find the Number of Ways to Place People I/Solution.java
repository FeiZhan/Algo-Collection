class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, Comparator.comparing((int[] point) -> point[0]).thenComparing((int[] point) -> point[1], Comparator.reverseOrder()));
        int length = points.length;
        int result = 0;
        for (int i = 0; i < length; i++) {
            int lowerY = -1;
            for (int j = i + 1; j < length; j++) {
                if (points[i][1] >= points[j][1]) {
                    if (lowerY < points[j][1]) {
                        result++;
                    }
                    lowerY = Math.max(lowerY, points[j][1]);
                }
                //System.out.println(i + " " + j + ": " + lowerY + ". " + result);
            }
        }

        return result;
    }
}
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int count = 0;
        Map<Integer, Integer> boom = new HashMap<Integer, Integer>();
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) {
                    continue;
                }
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int distance = x * x + y * y;
                boom.put(distance, boom.getOrDefault(distance, 0) + 1);
            }
            for (int value : boom.values()) {
                count += value * (value - 1);
            }
            boom.clear();
        }
        return count;
    }
}
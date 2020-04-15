class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        Map<Integer, Map<Integer, Integer>> cityMap = new HashMap<>();
        for (int[] edge : edges) {
            Map<Integer, Integer> neighbors = cityMap.getOrDefault(edge[0], new HashMap<>());
            neighbors.put(edge[1], edge[2]);
            cityMap.put(edge[0], neighbors);
            neighbors = cityMap.getOrDefault(edge[1], new HashMap<>());
            neighbors.put(edge[0], edge[2]);
            cityMap.put(edge[1], neighbors);
        }
        int minCount = Integer.MAX_VALUE;
        int result = -1;
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> distances = new HashMap<>();
            this.dfs(i, 0, distances, cityMap, distanceThreshold);
            int count = 0;
            for (int distance : distances.values()) {
                if (distance > 0 && distance <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                result = i;
            }
            System.out.println(i + " " + count + " " + minCount);
        }
        return result;
    }

    private void dfs(int current, int distance, Map<Integer, Integer> distances,
        final Map<Integer, Map<Integer, Integer>> cityMap, final int threshold) {
        if (distance >= distances.getOrDefault(current, threshold + 1)) {
            return;
        }
        distances.put(current, distance);
        Map<Integer, Integer> neighbors = cityMap.getOrDefault(current, new HashMap<>());
        for (int neighbor : neighbors.keySet()) {
            this.dfs(neighbor, distance + neighbors.get(neighbor), distances, cityMap, threshold);
        }
    }
}
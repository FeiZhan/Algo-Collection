class Solution {
    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        Map<Integer, Map<Integer, Integer>> childMap = new HashMap<>();
        for (int[] edge : edges) {
            Map<Integer, Integer> weights = childMap.getOrDefault(edge[0], new HashMap<Integer, Integer>());
            weights.put(edge[1], edge[2]);
            childMap.put(edge[0], weights);
            weights = childMap.getOrDefault(edge[1], new HashMap<Integer, Integer>());
            weights.put(edge[0], edge[2]);
            childMap.put(edge[1], weights);
        }

        int[] result = new int[childMap.size()];
        for (int root : childMap.keySet()) {
            List<Integer> validVertices = new LinkedList<>();
            Map<Integer, Integer> weights = childMap.get(root);
            for (int child : weights.keySet()) {
                int count = dfs(child, weights.get(child), root, childMap, signalSpeed);
                validVertices.add(count);
            }
            for (int i = 0; i < validVertices.size(); i++) {
                for (int j = i + 1; j < validVertices.size(); j++) {
                    result[root] += validVertices.get(i) * validVertices.get(j);
                }
            }
        }

        return result;
    }

    private int dfs(int current, int weight, int parent, Map<Integer, Map<Integer, Integer>> childMap, int signalSpeed) {
        int count = weight % signalSpeed == 0 ? 1 : 0;
        Map<Integer, Integer> weights = childMap.get(current);
        for (int child : weights.keySet()) {
            if (child == parent) {
                continue;
            }
            count += dfs(child, weights.get(child) + weight, current, childMap, signalSpeed);
        }

        return count;
    }
}
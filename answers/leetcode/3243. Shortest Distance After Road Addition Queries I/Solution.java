class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        Map<Integer, Integer> distanceMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            distanceMap.put(i, i);
        }
        Map<Integer, List<Integer>> nodeMap = new HashMap<>();
        for (int i = 1; i < n; i++) {
            List<Integer> list = new LinkedList<Integer>();
            list.add(i);
            nodeMap.put(i - 1, list);
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            List<Integer> list = nodeMap.get(query[0]);
            list.add(query[1]);
            dfs(query[0], distanceMap, nodeMap);
            result[i] = distanceMap.get(n - 1);
        }

        return result;
    }

    private void dfs(int current, Map<Integer, Integer> distanceMap, Map<Integer, List<Integer>> nodeMap) {
        int currentDistance = distanceMap.get(current);
        List<Integer> list = nodeMap.getOrDefault(current, Collections.emptyList());
        for (int next : list) {
            int distance = distanceMap.get(next);
            if (currentDistance + 1 < distance) {
                distanceMap.put(next, currentDistance + 1);
                dfs(next, distanceMap, nodeMap);
            }
        }
    }
}
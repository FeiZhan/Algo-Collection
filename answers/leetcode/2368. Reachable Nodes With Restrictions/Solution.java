class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        Set<Integer> restrictedSet = new HashSet<>();
        for (int node : restricted) {
            restrictedSet.add(node);
        }
        Map<Integer, Set<Integer>> nodeMap = new HashMap<>();
        for (int[] edge : edges) {
            if (restrictedSet.contains(edge[0]) || restrictedSet.contains(edge[1])) {
                continue;
            }
            Set<Integer> nodeSet = nodeMap.getOrDefault(edge[0], new HashSet<>());
            nodeSet.add(edge[1]);
            nodeMap.put(edge[0], nodeSet);
            nodeSet = nodeMap.getOrDefault(edge[1], new HashSet<>());
            nodeSet.add(edge[0]);
            nodeMap.put(edge[1], nodeSet);
        }
        Set<Integer> visited = new HashSet<>();
        dfs(0, visited, nodeMap);

        return visited.size();
    }

    private void dfs(int current, Set<Integer> visited, Map<Integer, Set<Integer>> nodeMap) {
        if (visited.contains(current)) {
            return;
        }

        visited.add(current);
        Set<Integer> nodeSet = nodeMap.getOrDefault(current, new HashSet<>());
        for (int next : nodeSet) {
            dfs(next, visited, nodeMap);
        }
    }
}
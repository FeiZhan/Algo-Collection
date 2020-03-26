class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (n > connections.length + 1) {
            return -1;
        }
        Map<Integer, List<Integer>> nodes = new HashMap<>();
        for (int[] connection : connections) {
            List<Integer> list = nodes.getOrDefault(connection[0], new LinkedList<>());
            list.add(connection[1]);
            nodes.put(connection[0], list);
            list = nodes.getOrDefault(connection[1], new LinkedList<>());
            list.add(connection[0]);
            nodes.put(connection[1], list);
        }
        int count = 0;
        Set<Integer> visited = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                count++;
                this.dfs(i, visited, nodes);
            }
        }
        return count - 1;
    }

    private void dfs(int current, Set<Integer> visited, Map<Integer, List<Integer>> nodes) {
        if (visited.contains(current)) {
            return;
        }
        visited.add(current);
        if (nodes.containsKey(current)) {
            List<Integer> list = nodes.get(current);
            for (int next : list) {
                this.dfs(next, visited, nodes);
            }
        }
    }
}
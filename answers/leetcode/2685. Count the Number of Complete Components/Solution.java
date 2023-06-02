class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            List<Integer> list = graph.getOrDefault(edge[0], new LinkedList<>());
            list.add(edge[1]);
            graph.put(edge[0], list);
            list = graph.getOrDefault(edge[1], new LinkedList<>());
            list.add(edge[0]);
            graph.put(edge[1], list);
        }

        int count = 0;
        Set<Integer> visited = new HashSet<>();

        for (int i = 0; i < n; i++) {
            List<Integer> result = dfs(i, visited, graph);
            if (result != null) {
                System.out.println(i + " " + result.toString());
            }
            if (result != null && (result.get(0) - 1) * result.get(0) == result.get(1)) {
                count++;
            }
        }

        return count;
    }

    private List<Integer> dfs(int current, Set<Integer> visited, Map<Integer, List<Integer>> graph) {
        if (visited.contains(current)) {
            return null;
        }

        visited.add(current);
        List<Integer> result = new ArrayList<>();
        result.add(1);
        result.add(0);

        if (!graph.containsKey(current)) {
            return result;
        }

        List<Integer> edges = graph.get(current);
        result.set(1, edges.size());
        for (int next : edges) {
            List<Integer> nextResult = dfs(next, visited, graph);
            if (nextResult != null) {
                result.set(0, result.get(0) + nextResult.get(0));
                result.set(1, result.get(1) + nextResult.get(1));
            }
        }

        return result;
    }
}
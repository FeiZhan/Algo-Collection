class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> results = new LinkedList<>();
        this.dfs(0, new LinkedList<>(), results, graph);
        return results;
    }

    private void dfs(int node, List<Integer> path, List<List<Integer>> results, int[][] graph) {
        if (node >= graph.length) {
            return;
        }

        path.add(node);
        if (node + 1 == graph.length) {
            results.add(new LinkedList<>(path));
            path.remove(path.size() - 1);
            return;
        }

        for (int next : graph[node]) {
            dfs(next, path, results, graph);
        }
        path.remove(path.size() - 1);
    }
}
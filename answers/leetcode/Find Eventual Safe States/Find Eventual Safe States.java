class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int[] safe = new int[graph.length];
        for (int i = 0; i < graph.length; i++) {
            this.dfs(i, new int[graph.length], safe, graph);
        }
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < safe.length; i++) {
            if (safe[i] == 1) {
                result.add(i);
            }
        }
        return result;
    }

    private boolean dfs(int index, int[] visited, int[] safe, int[][] graph) {
        if (safe[index] != 0) {
            return safe[index] == 1;
        }
        if (visited[index] != 0) {
            safe[index] = -1;
            visited[index] = 2;
            return false;
        }
        visited[index] = 1;
        for (int node : graph[index]) {
            if (!this.dfs(node, visited, safe, graph)) {
                safe[index] = -1;
                visited[index] = 2;
                return false;
            }
        }
        safe[index] = 1;
        visited[index] = 2;
        return true;
    }
}
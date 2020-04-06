class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        HashMap<Integer, Set<Integer>> poorer = new HashMap<>();
        for (int[] r : richer) {
            Set<Integer> p = poorer.getOrDefault(r[1], new HashSet<>());
            p.add(r[0]);
            poorer.put(r[1], p);
        }
        int[] result = new int[quiet.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = i;
        }
        boolean[] visited = new boolean[quiet.length];
        for (int key : poorer.keySet()) {
            this.dfs(key, result, visited, quiet, poorer);
        }
        return result;
    }

    private void dfs(int current, int[] result, boolean[] visited, int[] quiet, HashMap<Integer, Set<Integer>> poorer) {
        if (visited[current] || !poorer.containsKey(current)) {
            return;
        }
        visited[current] = true;
        Set<Integer> p = poorer.get(current);
        for (int next : p) {
            this.dfs(next, result, visited, quiet, poorer);
            if (quiet[result[next]] < quiet[result[current]])
            result[current] = result[next];
        }
    }
}
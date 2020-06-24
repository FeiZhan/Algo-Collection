class Solution {
    public int minReorder(int n, int[][] connections) {
        Map<Integer, List<Integer>> directed = new HashMap<>();
        Map<Integer, List<Integer>> reversed = new HashMap<>();
        for (int[] connection : connections) {
            List<Integer> list = directed.getOrDefault(connection[0], new LinkedList<>());
            list.add(connection[1]);
            directed.put(connection[0], list);
            list = reversed.getOrDefault(connection[1], new LinkedList<>());
            list.add(connection[0]);
            reversed.put(connection[1], list);
        }
        return this.dfs(0, new HashSet<>(), directed, reversed);
    }

    private int dfs(int current, Set<Integer> visited, Map<Integer, List<Integer>> directed, Map<Integer, List<Integer>> reversed) {
        if (visited.contains(current)) {
            return 0;
        }
        visited.add(current);
        int count = 0;
        List<Integer> list = reversed.getOrDefault(current, new LinkedList<>());
        for (int next : list) {
            count += this.dfs(next, visited, directed, reversed);
        }
        list = directed.getOrDefault(current, new LinkedList<>());
        for (int next : list) {
            if (!visited.contains(next)) {
                count += 1 + this.dfs(next, visited, directed, reversed);
            }
        }
        return count;
    }
}
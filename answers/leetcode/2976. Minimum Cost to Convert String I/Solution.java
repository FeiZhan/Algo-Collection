class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        Map<Character, Map<Character, Integer>> edges = new HashMap<>();
        for (int i = 0; i < original.length; i++) {
            Map<Character, Integer> map = edges.getOrDefault(original[i], new HashMap<>());
            int value = Math.min(cost[i], map.getOrDefault(changed[i], Integer.MAX_VALUE));
            map.put(changed[i], value);
            edges.put(original[i], map);
        }

        long[][] costs = new long[26][26];
        for (int i = 0; i < costs.length; i++) {
            Arrays.fill(costs[i], Long.MAX_VALUE);
            costs[i][i] = 0l;
        }
        for (char c : edges.keySet()) {
            dfs(c, new HashSet<>(), costs, edges);
        }

        long result = 0l;
        for (int i = 0; i < source.length(); i++) {
            long costValue = costs[(int)(source.charAt(i) - 'a')][(int)(target.charAt(i) - 'a')];
            if (costValue == Long.MAX_VALUE) {
                return -1l;
            }
            result += costValue;
        }

        return result;
    }

    private void dfs(char c, Set<Character> visited, long[][] costs, Map<Character, Map<Character, Integer>> edges) {
        if (visited.contains(c) || !edges.containsKey(c)) {
            return;
        }

        visited.add(c);
        int charValue = (int)(c - 'a');
        Map<Character, Integer> nextMap = edges.get(c);
        for (char next : nextMap.keySet()) {
            dfs(next, visited, costs, edges);
            int nextValue = (int)(next - 'a');
            int edge = nextMap.get(next);
            costs[charValue][nextValue] = Math.min(costs[charValue][nextValue], edge);
            for (int i = 0; i < 26; i++) {
                if (costs[nextValue][i] < Long.MAX_VALUE) {
                    costs[charValue][i] = Math.min(costs[charValue][i], costs[charValue][nextValue] + costs[nextValue][i]);
                }
            }
        }
    }
}
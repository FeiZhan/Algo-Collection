class Solution {
    public boolean canReach(int[] arr, int start) {
        return dfs(start, new HashSet<>(), arr);
    }

    private boolean dfs(int current, Set<Integer> visited, int[] values) {
        if (current < 0 || current >= values.length || visited.contains(current)) {
            return false;
        } else if (values[current] == 0) {
            return true;
        }

        visited.add(current);
        return dfs(current + values[current], visited, values) || dfs(current - values[current], visited, values);
    }
}
class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        Map<Integer, Set<Integer>> invocationMap = new HashMap<>();
        Map<Integer, Set<Integer>> reverseMap = new HashMap<>();
        for (int[] invocation : invocations) {
            Set<Integer> set = invocationMap.getOrDefault(invocation[0], new HashSet<>());
            set.add(invocation[1]);
            invocationMap.put(invocation[0], set);
            set = reverseMap.getOrDefault(invocation[1], new HashSet<>());
            set.add(invocation[0]);
            reverseMap.put(invocation[1], set);
        }

        Set<Integer> suspicious = new HashSet<>();
        dfs(k, suspicious, invocationMap);
        for (int node : suspicious) {
            Set<Integer> parentSet = reverseMap.getOrDefault(node, Collections.emptySet());
            parentSet.removeAll(suspicious);
            if (!parentSet.isEmpty()) {
                suspicious.clear();
                break;
            }
        }

        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (!suspicious.contains(i)) {
                result.add(i);
            }
        }

        return result;
    }

    private void dfs(int current, Set<Integer> suspicious, Map<Integer, Set<Integer>> invocationMap) {
        if (suspicious.contains(current)) {
            return;
        }
        suspicious.add(current);
        Set<Integer> childSet = invocationMap.getOrDefault(current, Collections.emptySet());
        for (int child : childSet) {
            dfs(child, suspicious, invocationMap);
        }
    }
}
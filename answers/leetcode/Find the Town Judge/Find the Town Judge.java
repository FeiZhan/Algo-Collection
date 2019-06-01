class Solution {
    public int findJudge(int N, int[][] trust) {
        Map<Integer, Set<Integer>> trustMap = new HashMap<>();
        for (int[] t : trust) {
            Set<Integer> trustSet = trustMap.getOrDefault(t[0], new HashSet<>());
            trustSet.add(t[1]);
            trustMap.put(t[0], trustSet);
        }
        if (trustMap.size() != N - 1) {
            return -1;
        }
        Set<Integer> judges = IntStream.range(1, N + 1).boxed().collect(Collectors.toSet());
        for (Set<Integer> trustSet : trustMap.values()) {
            judges.retainAll(trustSet);
        }
        for (int judge : judges) {
            if (!trustMap.containsKey(judge)) {
                return judge;
            }
        }
        return -1;
    }
}
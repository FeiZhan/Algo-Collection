class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        Map<Integer, Set<Integer>> dislikeMap = new HashMap<>();
        for (int[] dislike : dislikes) {
            Set<Integer> dislikeSet = dislikeMap.getOrDefault(dislike[0], new HashSet<>());
            dislikeSet.add(dislike[1]);
            dislikeMap.put(dislike[0], dislikeSet);
            dislikeSet = dislikeMap.getOrDefault(dislike[1], new HashSet<>());
            dislikeSet.add(dislike[0]);
            dislikeMap.put(dislike[1], dislikeSet);
        }
        Map<Integer, Boolean> partition = new HashMap<>();
        for (int i = 0; i < N; i++) {
            if (!partition.containsKey(i) && !this.dfs(i, true, dislikeMap, partition)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfs(int index, boolean current, Map<Integer, Set<Integer>> dislikeMap, Map<Integer, Boolean> partition) {
        if (partition.containsKey(index)) {
            return partition.get(index) == current;
        }
        partition.put(index, current);
        if (!dislikeMap.containsKey(index)) {
            return true;
        }
        Set<Integer> dislikeSet = dislikeMap.get(index);
        for (int next : dislikeSet) {
            if (partition.containsKey(next) && partition.get(next) == current) {
                return false;
            }
            this.dfs(next, !current, dislikeMap, partition);
        }
        return true;
    }
}
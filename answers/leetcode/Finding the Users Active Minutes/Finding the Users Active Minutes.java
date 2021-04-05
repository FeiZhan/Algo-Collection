class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> users = new HashMap<>();
        for (int[] log : logs) {
            users.putIfAbsent(log[0], new HashSet<>());
            users.get(log[0]).add(log[1]);
        }

        int[] result = new int[k];
        for (Set<Integer> set : users.values()) {
            int size = set.size();
            if (size > 0 && size <= k) {
                result[size - 1]++;
            }
        }

        return result;
    }
}
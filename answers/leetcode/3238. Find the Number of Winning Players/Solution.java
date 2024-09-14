class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        Map<Integer, Map<Integer, Integer>> playerMap = new HashMap<>();
        for (int[] p : pick) {
            Map<Integer, Integer> map = playerMap.getOrDefault(p[0], new HashMap<>());
            map.put(p[1], map.getOrDefault(p[1], 0) + 1);
            playerMap.put(p[0], map);
        }

        int result = 0;
        for (int player : playerMap.keySet()) {
            Map<Integer, Integer> map = playerMap.get(player);
            int max = 0;
            for (int count : map.values()) {
                max = Math.max(max, count);
            }
            result += max > player ? 1 : 0;
        }

        return result;
    }
}
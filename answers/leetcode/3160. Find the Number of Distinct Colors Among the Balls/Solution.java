class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int[] result = new int[queries.length];
        Map<Integer, Integer> colors = new HashMap<>();
        Map<Integer, Set<Integer>> balls = new HashMap<>();

        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            if (colors.containsKey(query[0])) {
                int color = colors.get(query[0]);
                Set<Integer> ballSet = balls.get(color);
                ballSet.remove(query[0]);
                if (ballSet.isEmpty()) {
                    balls.remove(color);
                }
            }
            colors.put(query[0], query[1]);
            Set<Integer> ballSet = balls.getOrDefault(query[1], new HashSet<>());
            ballSet.add(query[0]);
            balls.put(query[1], ballSet);
            result[i] = balls.size();
        }

        return result;
    }
}
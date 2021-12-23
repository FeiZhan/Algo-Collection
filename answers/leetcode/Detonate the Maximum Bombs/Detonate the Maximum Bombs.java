class Solution {
    public int maximumDetonation(int[][] bombs) {
        Map<Integer, List<Integer>> bombMap = new HashMap<>();
        for (int i = 0; i < bombs.length; i++) {
            int[] bomb = bombs[i];
            List<Integer> neighbors = new LinkedList<>();
            for (int j = 0; j < bombs.length; j++) {
                int[] bomb1 = bombs[j];
                long x = bomb[0] - bomb1[0];
                long y = bomb[1] - bomb1[1];
                long distance = x * x + y * y;
                long range = (long)(bomb[2]) * bomb[2];
                if (distance <= range) {
                    neighbors.add(j);
                }
            }
            bombMap.put(i, neighbors);
        }

        int result = 0;
        for (int i = 0; i < bombs.length; i++) {
            int count = this.detonate(i, new HashSet<>(), bombMap);
            result = Math.max(result, count);
        }

        return result;
    }

    private int detonate(int index, Set<Integer> visited, Map<Integer, List<Integer>> bombMap) {
        if (visited.contains(index)) {
            return 0;
        }

        visited.add(index);
        int count = 1;
        List<Integer> neighbors = bombMap.getOrDefault(index, new LinkedList<>());

        for (int neighbor : neighbors) {
            count += this.detonate(neighbor, visited, bombMap);
        }

        return count;
    }
}
//Runtime: 410 ms, faster than 6.70% of Java online submissions for Detonate the Maximum Bombs.
//Memory Usage: 74.9 MB, less than 5.06% of Java online submissions for Detonate the Maximum Bombs.

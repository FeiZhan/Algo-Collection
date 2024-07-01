class Solution {
    public int minimumOperationsToMakeEqual(int x, int y) {
        Set<Integer> nextQueue = new HashSet<>();
        nextQueue.add(y);
        int distance = 0;
        Map<Integer, Integer> distances = new HashMap<>();

        while (!nextQueue.isEmpty()) {
            Set<Integer> queue = new HashSet<>(nextQueue);
            nextQueue.clear();
            for (int current : queue) {
                if (current == x) {
                    return distance;
                } else if (distances.containsKey(current) || current < 0 || current > x + y + 1) {
                    continue;
                }
                distances.put(current, distance);
                nextQueue.add(current - 1);
                nextQueue.add(current + 1);
                nextQueue.add(current * 5);
                nextQueue.add(current * 11);
            }
            distance++;
        }

        return -1;
    }
}
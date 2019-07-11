class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, Map<Integer, Integer>> network = new HashMap<>();
        for (int i = 0; i < times.length; i++) {
            Map<Integer, Integer> map = network.getOrDefault(times[i][0], new HashMap<>());
            map.put(times[i][1], times[i][2]);
            network.put(times[i][0], map);
        }
        Map<Integer, Integer> delays = new HashMap<>();
        delays.put(K, 0);
        PriorityQueue<Integer> nextQueue = new PriorityQueue<>(Comparator.comparing(delays::get));
        nextQueue.add(K);
        while (!nextQueue.isEmpty()) {
            PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.comparing(delays::get));
            queue.addAll(nextQueue);
            nextQueue.clear();
            while (!queue.isEmpty()) {
                int current = queue.poll();
                Map<Integer, Integer> map = network.getOrDefault(current, new HashMap<>());
                for (int target : map.keySet()) {
                    int delay = delays.get(current) + map.get(target);
                    if (delays.getOrDefault(target, Integer.MAX_VALUE) > delay) {
                        delays.put(target, delay);
                        nextQueue.add(target);
                    }
                }
            }
        }
        if (delays.size() < N) {
            return -1;
        }
        int maxDelay = 0;
        for (int delay : delays.values()) {
            maxDelay = Math.max(maxDelay, delay);
        }
        return maxDelay;
    }
}

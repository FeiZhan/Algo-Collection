class Solution {
    public int maxPointsInsideSquare(int[][] points, String s) {
        Map<Integer, Integer> lengthMap = new HashMap<>();
        Map<Character, PriorityQueue<Integer>> charMap = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            int length = Math.max(Math.abs(points[i][0]), Math.abs(points[i][1]));
            lengthMap.put(length, lengthMap.getOrDefault(length, 0) + 1);
            char c = s.charAt(i);
            PriorityQueue<Integer> queue = charMap.getOrDefault(c, new PriorityQueue<>());
            queue.add(length);
            charMap.put(c, queue);
        }
        int length = Integer.MAX_VALUE;
        for (PriorityQueue<Integer> queue : charMap.values()) {
            if (queue.size() <= 1) {
                continue;
            }
            queue.poll();
            length = Math.min(length, queue.poll() - 1);
        }
        int result = 0;
        for (int l : lengthMap.keySet()) {
            result += l <= length ? lengthMap.get(l) : 0;
        }

        return result;
    }
}
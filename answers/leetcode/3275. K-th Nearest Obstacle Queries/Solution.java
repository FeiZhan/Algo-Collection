class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        int length = queries.length;
        int[] result = new int[length];
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < length; i++) {
            int[] query = queries[i];
            int distance = Math.abs(query[0]) + Math.abs(query[1]);
            queue.add(distance);
            while (queue.size() > k) {
                queue.poll();
            }
            result[i] = queue.size() >= k ? queue.peek() : -1;
        }

        return result;
    }
}
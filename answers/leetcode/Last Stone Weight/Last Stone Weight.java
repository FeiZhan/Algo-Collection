class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone : stones) {
            queue.add(stone);
        }
        while (queue.size() >= 2) {
            int stone0 = queue.poll();
            int stone1 = queue.poll();
            if (stone0 != stone1) {
                queue.add(stone0 - stone1);
            }
        }
        return queue.isEmpty() ? 0 : queue.poll();
    }
}
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 1; i < heights.length; i++) {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0) {
                continue;
            }
            queue.add(diff);
            while (queue.size() > ladders) {
                int smallest = queue.poll();
                if (smallest > bricks) {
                    return i - 1;
                } else {
                    bricks -= smallest;
                }
            }
        }

        return heights.length - 1;
    }
}
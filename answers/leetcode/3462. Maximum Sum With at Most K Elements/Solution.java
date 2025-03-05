class Solution {
    public long maxSum(int[][] grid, int[] limits, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < grid.length; i++) {
            PriorityQueue<Integer> rowQueue = new PriorityQueue<>(Collections.reverseOrder());
            for (int j = 0; j < grid[i].length; j++) {
                rowQueue.add(grid[i][j]);
            }
            for (int j = 0; j < limits[i]; j++) {
                queue.add(rowQueue.poll());
            }
            while (queue.size() > k) {
                queue.poll();
            }
        }
        long result = 0l;
        for (int number : queue) {
            result += number;
        }

        return result;
    }
}
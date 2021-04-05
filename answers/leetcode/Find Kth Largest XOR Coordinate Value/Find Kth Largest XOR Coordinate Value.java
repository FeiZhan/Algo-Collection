class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int height = matrix.length;
        int width = matrix[0].length;
        int[][] dp = new int[height][width];
        PriorityQueue<Integer> queue = new PriorityQueue<>();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                dp[i][j] = matrix[i][j];
                if (i > 0) {
                    dp[i][j] ^= dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] ^= dp[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    dp[i][j] ^= dp[i - 1][j - 1];
                }
                queue.add(dp[i][j]);
                if (queue.size() > k) {
                    queue.poll();
                }
            }
        }

        return queue.poll();
    }
}
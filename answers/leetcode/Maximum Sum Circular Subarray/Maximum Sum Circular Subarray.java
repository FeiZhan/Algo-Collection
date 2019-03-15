class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int maxSum = Integer.MIN_VALUE;
        int minSum = Integer.MAX_VALUE;
        int sum0 = 0;
        int sum1 = 0;
        int total = 0;
        for (int number : A) {
            total += number;
            sum0 += number;
            maxSum = Math.max(maxSum, sum0);
            if (sum0 < 0) {
                sum0 = 0;
            }
            sum1 += number;
            minSum = Math.min(minSum, sum1);
            if (sum1 > 0) {
                sum1 = 0;
            }
        }
        if (total == minSum) {
            return maxSum;
        } else {
            return Math.max(maxSum, total - minSum);
        }
    }
}
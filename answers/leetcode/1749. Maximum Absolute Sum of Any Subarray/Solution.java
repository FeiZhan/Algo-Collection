class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int maxCurrent = 0;
        int maxSum = 0;
        int minCurrent = 0;
        int minSum = 0;
        for (int number : nums) {
            maxCurrent = Math.max(maxCurrent + number, number);
            maxSum = Math.max(maxSum, maxCurrent);
            minCurrent = Math.min(minCurrent + number, number);
            minSum = Math.min(minSum, minCurrent);
        }

        return Math.max(maxSum, -minSum);
    }
}
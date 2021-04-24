class Solution {
    public int largestAltitude(int[] gain) {
        int maxSum = 0;
        int sum = 0;

        for (int number : gain) {
            sum += number;
            maxSum = Math.max(maxSum, sum);
        }

        return maxSum;
    }
}
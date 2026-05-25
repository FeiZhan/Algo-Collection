class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i + 1 < k; i++) {
            sum += nums[i];
        }
        int max = Integer.MIN_VALUE;
        for (int i = k - 1; i < nums.length; i++) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
            max = Math.max(max, sum);
        }
        return (double)max / k;
    }
}
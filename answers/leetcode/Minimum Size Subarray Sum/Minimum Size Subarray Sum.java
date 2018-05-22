class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int length = Integer.MAX_VALUE;
        int sum = 0;
        for (int i = 0, j = 0; j < nums.length; j++) {
            sum += nums[j];
            while (i <= j && sum - nums[i] >= s) {
                sum -= nums[i];
                i++;
            }
            if (sum >= s) {
                length = Math.min(length, j - i + 1);
            }
        }
        return length == Integer.MAX_VALUE ? 0 : length;
    }
}
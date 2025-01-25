class Solution {
    public int subarraySum(int[] nums) {
        int sum = 0;
        int[] sums = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int start = Math.max(0, i - nums[i]);
            result += sums[i] - (start > 0 ? sums[start - 1] : 0);
        }

        return result;
    }
}
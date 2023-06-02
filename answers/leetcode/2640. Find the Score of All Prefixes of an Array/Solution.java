class Solution {
    public long[] findPrefixScore(int[] nums) {
        int max = 0;
        long sum = 0;
        long[] result = new long[nums.length];
        for (int i = 0; i < nums.length; i++) {
            max = Math.max(max, nums[i]);
            sum += nums[i] + max;
            result[i] = sum;
        }

        return result;
    }
}
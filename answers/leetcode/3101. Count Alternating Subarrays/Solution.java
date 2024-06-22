class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long result = 1l;
        long[] dp = new long[nums.length];
        dp[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            dp[i] = (nums[i] != nums[i - 1] ? dp[i - 1] : 0) + 1;
            result += dp[i];
        }

        return result;
    }
}
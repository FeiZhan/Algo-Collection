class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0;
        int longest = 0;
        int zeroCount = 0;
        for (int i = 0; i < nums.length; i++) {
            zeroCount += nums[i] == 0 ? 1 : 0;
            while (zeroCount > 1) {
                zeroCount -= nums[left] == 0 ? 1 : 0;
                left++;
            }
            longest = Math.max(longest, i - left + 1);
        }
        return Math.max(longest - 1, 0);
    }
}
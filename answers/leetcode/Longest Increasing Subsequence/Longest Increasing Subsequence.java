class Solution {
    public int lengthOfLIS(int[] nums) {
        int maxLength = 0;
        int[] lengths = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            lengths[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lengths[i] = Math.max(lengths[i], lengths[j] + 1);
                }
            }
            maxLength = Math.max(maxLength, lengths[i]);
        }
        return maxLength;
    }
}
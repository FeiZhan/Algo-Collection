class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int length = 0;
        for (int i = 0, j = 1; j <= nums.length; j++) {
            if (j == nums.length || nums[j] <= nums[j - 1]) {
                length = Math.max(length, j - i);
                i = j;
            }
        }
        return length;
    }
}
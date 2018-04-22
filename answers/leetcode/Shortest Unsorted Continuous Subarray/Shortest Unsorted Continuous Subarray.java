class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int left = -1;
        int right = -1;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < max) {
                right = i;
            }
            max = Math.max(max, nums[i]);
        }
        int min = Integer.MAX_VALUE;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] > min) {
                left = i;
            }
            min = Math.min(min, nums[i]);
        }
        return left == -1 && right == -1 ? 0 : right - left + 1;
    }
}
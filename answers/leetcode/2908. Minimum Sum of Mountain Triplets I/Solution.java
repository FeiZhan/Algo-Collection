class Solution {
    public int minimumSum(int[] nums) {
        int length = nums.length;
        int[] left = new int[length];
        int[] right = new int[length];
        for (int i = 0; i < length; i++) {
            left[i] = Math.min(nums[i], i > 0 ? left[i - 1] : Integer.MAX_VALUE);
            right[length - i - 1] = Math.min(nums[length - i - 1], i > 0 ? right[length - i] : Integer.MAX_VALUE);
        }
        int result = Integer.MAX_VALUE;
        for (int i = 1; i + 1 < length; i++) {
            if (left[i - 1] < nums[i] && nums[i] > right[i + 1]) {
                result = Math.min(result, left[i - 1] + nums[i] + right[i + 1]);
            }
        }

        return result < Integer.MAX_VALUE ? result : -1;
    }
}
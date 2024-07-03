class Solution {
    public int minimumSum(int[] nums) {
        int length = nums.length;
        int min = Integer.MAX_VALUE;
        int[] minimums = new int[length];
        for (int i = 0; i < length; i++) {
            min = Math.min(min, nums[i]);
            minimums[i] = min;
        }

        min = Integer.MAX_VALUE;
        int result = Integer.MAX_VALUE;
        for (int i = length - 2; i > 0; i--) {
            min = Math.min(min, nums[i + 1]);
            if (minimums[i - 1] < nums[i] && nums[i] > min) {
                result = Math.min(result, minimums[i - 1] + nums[i] + min);
            }
        }

        return result < Integer.MAX_VALUE ? result : -1;
    }
}
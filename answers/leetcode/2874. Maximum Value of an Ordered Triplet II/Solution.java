class Solution {
    public long maximumTripletValue(int[] nums) {
        int length = nums.length;
        int[] maxRight = new int[length];
        maxRight[length - 1] = nums[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            maxRight[i] = Math.max(maxRight[i + 1], nums[i]);
        }

        int maxLeft = 0;
        long result = 0l;
        for (int i = 1; i + 1 < length; i++) {
            maxLeft = Math.max(maxLeft, nums[i - 1]);
            result = Math.max(result, (long)(maxLeft - nums[i]) * (long)maxRight[i + 1]);
        }

        return result;
    }
}
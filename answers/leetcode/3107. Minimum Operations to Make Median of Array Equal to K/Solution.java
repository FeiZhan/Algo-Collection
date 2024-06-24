class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        Arrays.sort(nums);
        int medianIndex = (int)Math.ceil((double)(nums.length - 1) / 2.0);
        long result = 0l;

        if (nums[medianIndex] < k) {
            for (int i = medianIndex; i < nums.length && nums[i] < k; i++) {
                result += (long)(k - nums[i]);
            }
        } else {
            for (int i = medianIndex; i >= 0 && nums[i] > k; i--) {
                result += (long)(nums[i] - k);
            }
        }

        return result;
    }
}
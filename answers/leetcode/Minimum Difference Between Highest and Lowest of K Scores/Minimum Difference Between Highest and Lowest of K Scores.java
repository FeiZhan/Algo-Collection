class Solution {
    public int minimumDifference(int[] nums, int k) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }

        Arrays.sort(nums);
        int result = Integer.MAX_VALUE;
        for (int i = k - 1; i < nums.length; i++) {
            result = Math.min(result, nums[i] - nums[i - k + 1]);
        }

        return result;
    }
}
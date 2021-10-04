class Solution {
    public int maximumDifference(int[] nums) {
        int min = nums[0];
        int result = 0;

        for (int i = 1; i < nums.length; i++) {
            result = Math.max(result, nums[i] - min);
            min = Math.min(min, nums[i]);
        }

        return result > 0 ? result : -1;
    }
}
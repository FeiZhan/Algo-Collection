class Solution {
    public int minDifference(int[] nums) {
        Arrays.sort(nums);
        int result = Integer.MAX_VALUE;
        for (int i = 0; i <= 3 && i < nums.length; i++) {
            for (int j = 0; i + j <= 3 && j <= nums.length - 1; j++) {
                result = Math.min(result, Math.abs(nums[nums.length - j - 1] - nums[i]));
            }
        }

        return result;
    }
}
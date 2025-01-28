class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            result = Math.max(result, Math.abs(nums[i] - nums[(i + nums.length - 1) % nums.length]));
        }

        return result;
    }
}
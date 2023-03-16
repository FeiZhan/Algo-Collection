class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int result = nums[nums.length - 2] - nums[1];
        result = Math.min(result, nums[nums.length - 3] - nums[0]);
        result = Math.min(result, nums[nums.length - 1] - nums[2]);

        return result;
    }
}
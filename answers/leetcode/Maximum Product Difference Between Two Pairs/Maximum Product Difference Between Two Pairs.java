class Solution {
    public int maxProductDifference(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        return nums[length - 1] * nums[length - 2] - nums[0] * nums[1];
    }
}
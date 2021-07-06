class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int result = 0;
        for (int i = 0; i * 2 < nums.length; i++) {
            result = Math.max(result, nums[i] + nums[nums.length - i - 1]);
        }

        return result;
    }
}
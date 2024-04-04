class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int result = Integer.MAX_VALUE;
        for (int i = 1; i < nums.length; i++) {
            result = Math.min(result, nums[i] - nums[i - 1]);
        }

        return result;
    }
}
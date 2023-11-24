class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int right = 0;
        for (int number : nums) {
            right += number;
        }

        int left = 0;
        int[] result = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            right -= nums[i];
            result[i] = nums[i] * i - left + right - nums[i] * (nums.length - i - 1);
            left += nums[i];
        }

        return result;
    }
}
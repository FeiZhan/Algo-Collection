class Solution {
    public int waysToSplitArray(int[] nums) {
        long right = 0l;
        for (int number : nums) {
            right += number;
        }

        long left = 0l;
        int result = 0;
        for (int i = 0; i + 1 < nums.length; i++) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) {
                result++;
            }
        }

        return result;
    }
}
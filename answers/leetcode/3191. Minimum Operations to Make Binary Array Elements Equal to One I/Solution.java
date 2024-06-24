class Solution {
    public int minOperations(int[] nums) {
        int length = nums.length;
        int result = 0;
        for (int i = 2; i < length; i++) {
            if (nums[i - 2] == 0) {
                nums[i - 2] = 1;
                nums[i - 1] = nums[i - 1] == 0 ? 1 : 0;
                nums[i] = nums[i] == 0 ? 1 : 0;
                result++;
            }
        }

        return nums[length - 1] == 1 && nums[length - 2] == 1 ? result : -1;
    }
}
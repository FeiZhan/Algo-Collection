class Solution {
    public int firstMissingPositive(int[] nums) {
        int temp = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                temp = nums[i];
                break;
            }
        }
        if (temp == 0) {
            return 1;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= 0) {
                nums[i] = temp;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            int num = Math.abs(nums[i]);
            if (num <= nums.length && nums[num - 1] > 0) {
                nums[num - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }
}
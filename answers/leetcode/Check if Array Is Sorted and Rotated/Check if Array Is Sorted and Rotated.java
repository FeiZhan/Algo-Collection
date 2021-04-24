class Solution {
    public boolean check(int[] nums) {
        boolean isDecreasing = false;
        int length = nums.length;

        for (int i = 1; i < length; i++) {
            if (nums[i - 1] > nums[i]) {
                if (isDecreasing) {
                    return false;
                }
                isDecreasing = true;
            }
        }

        return !isDecreasing || nums[0] >= nums[length - 1];
    }
}
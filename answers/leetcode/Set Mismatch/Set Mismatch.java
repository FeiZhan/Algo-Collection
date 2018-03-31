class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] error = new int[2];
        for (int num : nums) {
            int abs = Math.abs(num);
            if (nums[abs - 1] > 0) {
                nums[abs - 1] *= -1;
            } else {
                error[0] = abs;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                error[1] = i + 1;
            }
        }
        return error;
    }
}
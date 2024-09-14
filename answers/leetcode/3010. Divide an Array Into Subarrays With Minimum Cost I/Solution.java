class Solution {
    public int minimumCost(int[] nums) {
        int[] minNumbers = new int[]{Integer.MAX_VALUE, Integer.MAX_VALUE};
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= minNumbers[0]) {
                minNumbers[1] = minNumbers[0];
                minNumbers[0] = nums[i];
            } else if (nums[i] < minNumbers[1]) {
                minNumbers[1] = nums[i];
            }
        }

        return nums[0] + minNumbers[0] + minNumbers[1];
    }
}
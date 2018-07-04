class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int[] rob0 = new int[nums.length];
        for (int i = 0; i + 1 < nums.length; i++) {
            int money = nums[i];
            if (i >= 2) {
                money = Math.max(money, rob0[i - 2] + nums[i]);
            }
            if (i >= 1) {
                money = Math.max(money, rob0[i - 1]);
            }
            rob0[i] = money;
        }
        int[] rob1 = new int[nums.length];
        for (int i = 1; i < nums.length; i++) {
            int money = nums[i];
            if (i >= 2) {
                money = Math.max(money, rob1[i - 2] + nums[i]);
            }
            if (i >= 1) {
                money = Math.max(money, rob1[i - 1]);
            }
            rob1[i] = money;
        }
        return Math.max(rob0[nums.length - 2], rob1[nums.length - 1]);
    }
}
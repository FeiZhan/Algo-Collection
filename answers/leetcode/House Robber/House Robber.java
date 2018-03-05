class Solution {
    public int rob(int[] nums) {
        int[] maxRob = new int[nums.length];
        if (nums.length > 0) {
            maxRob[0] = nums[0];
        }
        if (nums.length > 1) {
            maxRob[1] = Math.max(nums[0], nums[1]);
        }
        for (int i = 2; i < nums.length; i++) {
            maxRob[i] = Math.max(maxRob[i - 1], maxRob[i - 2] + nums[i]);
        }
        return maxRob.length > 0 ? maxRob[maxRob.length - 1] : 0;
    }
}
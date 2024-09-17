class Solution {
    public int maxOperations(int[] nums) {
        int sum = nums[0] + nums[1];
        int result = 1;
        for (int i = 3; i < nums.length; i += 2) {
            if (nums[i - 1] + nums[i] == sum) {
                result++;
            } else {
                break;
            }
        }

        return result;
    }
}
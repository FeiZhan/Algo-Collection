class Solution {
    public int minOperations(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] + result) % 2 == 0) {
                result++;
            }
        }

        return result;
    }
}
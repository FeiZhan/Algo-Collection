class Solution {
    public int findMiddleIndex(int[] nums) {
        int sum = 0;
        for (int number : nums) {
            sum += number;
        }

        int left = 0;
        for (int i = 0; i < nums.length; i++) {
            if (left * 2 + nums[i] == sum) {
                return i;
            }
            left += nums[i];
        }

        return -1;
    }
}
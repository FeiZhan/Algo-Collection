class Solution {
    public long zeroFilledSubarray(int[] nums) {
        int left = 0;
        long result = 0l;
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            if (number == 0) {
                result += i - left + 1;
            } else {
                left = i + 1;
            }
        }

        return result;
    }
}
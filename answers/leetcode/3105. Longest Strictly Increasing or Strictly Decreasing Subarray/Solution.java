class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int type = 0;
        int left = 0;
        int result = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i] && type != 1) {
                type = 1;
                left = i - 1;
            } else if (nums[i - 1] > nums[i] && type != -1) {
                type = -1;
                left = i - 1;
            } else if (nums[i - 1] == nums[i]) {
                type = 0;
                left = i;
            }
            result = Math.max(result, i - left + 1);
        }
        
        return result;
    }
}
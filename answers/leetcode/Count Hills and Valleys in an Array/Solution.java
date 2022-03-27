class Solution {
    public int countHillValley(int[] nums) {
        int result = 0;
        int left = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i]) {
                if (left == 2) {
                    result++;
                }
                left = 1;
            } else if (nums[i - 1] > nums[i]) {
                if (left == 1) {
                    result++;
                }
                left = 2;
            }
        }

        return result;
    }
}
//Runtime: 1 ms, faster than 81.67% of Java online submissions for Count Hills and Valleys in an Array.
//Memory Usage: 42 MB, less than 65.59% of Java online submissions for Count Hills and Valleys in an Array.

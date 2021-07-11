class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int result = Integer.MAX_VALUE / 2;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target && Math.abs(start - i) < Math.abs(start - result)) {
                result = i;
            }
        }

        return Math.abs(start - result);
    }
}
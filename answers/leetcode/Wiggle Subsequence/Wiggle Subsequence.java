class Solution {
    public int wiggleMaxLength(int[] nums) {
        int length = 0;
        if (nums.length > 0) {
            length = 1;
        }
        Boolean increase = null;
        for (int i = 1; i < nums.length; i++) {
            if ((increase == null || increase) && nums[i] < nums[i - 1]) {
                length++;
                increase = false;
            } else if ((increase == null || !increase) && nums[i] > nums[i - 1]) {
                length++;
                increase = true;
            }
        }
        return length;
    }
}
class Solution {
    public void sortColors(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        for (int i = 0; i < nums.length && i <= right; i++) {
            int temp = nums[i];
            if (nums[i] == 0 && i > left) {
                nums[i] = nums[left];
                nums[left] = temp;
                left++;
                i--;
            } else if (nums[i] == 2) {
                nums[i] = nums[right];
                nums[right] = temp;
                right--;
                i--;
            }
        }
    }
}
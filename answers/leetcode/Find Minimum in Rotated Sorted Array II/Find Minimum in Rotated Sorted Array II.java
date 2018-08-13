class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            int middle = (left + right) / 2;
            if (nums[middle] > nums[left]) {
                left = middle + 1;
            } else if (nums[middle] < nums[left]) {
                right = middle;
            } else {
                left++;
            }
        }
        return nums[left];
    }
}
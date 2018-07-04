class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if ((middle == 0 || nums[middle] > nums[middle - 1]) && (middle == nums.length - 1 || nums[middle] > nums[middle + 1])) {
                return middle;
            } else if (middle > 0 && nums[middle] < nums[middle - 1]) {
                right--;
            } else {
                left++;
            }
        }
        return -1;
    }
}
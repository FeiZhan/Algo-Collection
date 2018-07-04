class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] range = new int[2];
        range[0] = -1;
        range[1] = -1;
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] > target || (nums[middle] == target && middle > 0 && nums[middle - 1] == target)) {
                right--;
            } else if (nums[middle] < target) {
                left++;
            } else {
                range[0] = middle;
                break;
            }
        }
        
        left = 0;
        right = nums.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] > target) {
                right--;
            } else if (nums[middle] < target || (nums[middle] == target && middle + 1 < nums.length && nums[middle + 1] == target)) {
                left++;
            } else {
                range[1] = middle;
                break;
            }
        }
        return range;
    }
}
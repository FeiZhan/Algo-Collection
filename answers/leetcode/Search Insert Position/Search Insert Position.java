class Solution {
    public int searchInsert(int[] nums, int target) {
        if (null == nums || nums.length == 0 || target <= nums[0]) {
            return 0;
        }
        
        for (int i = 1; i < nums.length; i ++) {
            if (target > nums[i - 1] && target <= nums[i]) {
                return i;
            }
        }
        return nums.length;
    }
}

class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (target == nums[middle]) {
                return middle;
            } else if (target < nums[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
}
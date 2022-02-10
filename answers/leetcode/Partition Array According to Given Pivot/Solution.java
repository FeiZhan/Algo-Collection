class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int left = 0;
        int right = nums.length - 1;
        int[] result = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < pivot) {
                result[left] = nums[i];
                left++;
            }
            if (nums[nums.length - i - 1] > pivot) {
                result[right] = nums[nums.length - i - 1];
                right--;
            }
        }

        for (int i = left; i <= right; i++) {
            result[i] = pivot;
        }

        return result;
    }
}
//Runtime: 7 ms, faster than 87.22% of Java online submissions for Partition Array According to Given Pivot.
//Memory Usage: 168.4 MB, less than 45.17% of Java online submissions for Partition Array According to Given Pivot.

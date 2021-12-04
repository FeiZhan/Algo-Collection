class Solution {
    public int removeDuplicates(int[] nums) {
        int left = 2;
        for (int i = 2; i < nums.length; i++) {
            if (nums[left - 2] < nums[i]) {
                nums[left] = nums[i];
                left++;
            }
        }
        return left - 1;
    }
}
//Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted Array II.
//Memory Usage: 39 MB, less than 89.49% of Java online submissions for Remove Duplicates from Sorted Array II.

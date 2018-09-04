class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 1;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] != nums[index] || nums[i] != nums[index - 1]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
}
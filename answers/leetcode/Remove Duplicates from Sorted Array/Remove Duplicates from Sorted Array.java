class Solution {
    public int removeDuplicates(int[] nums) {
        int current = 0;
        for (int num : nums) {
            if (num != nums[current]) {
                current += 1;
                nums[current] = num;
            }
        }
        return current + 1;
    }
}
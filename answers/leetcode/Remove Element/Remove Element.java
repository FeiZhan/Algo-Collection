class Solution {
    public int removeElement(int[] nums, int val) {
        int current = 0;
        for (int num : nums) {
            if (num != val) {
                nums[current] = num;
                current ++;
            }
        }
        return current;
    }
}
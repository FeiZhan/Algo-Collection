class Solution {
    public int minPatches(int[] nums, int n) {
        int patches = 0;
        int index = 0;
        for (long i = 1l; i <= n;) {
            if (index < nums.length && nums[index] <= i) {
                i += nums[index];
                index++;
            } else {
                i *= 2;
                patches++;
            }
        }
        return patches;
    }
}
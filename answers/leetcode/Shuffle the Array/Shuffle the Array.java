class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] result = new int[nums.length];
        for (int i = 0; i + i < nums.length; i++) {
            result[i + i] = nums[i];
            result[i + i + 1] = nums[i + nums.length / 2];
        }
        return result;
    }
}
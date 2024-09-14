class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int k = (1 << maximumBit) - 1;
        int[] result = new int[nums.length];
        result[nums.length - 1] = nums[0] ^ k;
        for (int i = 1; i < nums.length; i++) {
            result[nums.length - i - 1] = result[nums.length - i] ^ nums[i];
        }

        return result;
    }
}
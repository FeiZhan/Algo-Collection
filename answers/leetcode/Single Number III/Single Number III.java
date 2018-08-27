class Solution {
    public int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        int bit = xor & -xor;
        int[] result = new int[2];
        for (int num : nums) {
            result[(num & bit) > 0 ? 1 : 0] ^= num;
        }
        return result;
    }
}
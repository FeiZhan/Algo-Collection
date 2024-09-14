class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        int result = 0;
        for (int number1 : nums1) {
            for (int number2 : nums2) {
                result += number1 % (number2 * k) == 0 ? 1 : 0;
            }
        }

        return result;
    }
}
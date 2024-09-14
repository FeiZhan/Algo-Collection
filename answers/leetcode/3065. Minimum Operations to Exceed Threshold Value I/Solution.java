class Solution {
    public int minOperations(int[] nums, int k) {
        int result = 0;
        for (int number : nums) {
            result += number < k ? 1 : 0;
        }

        return result;
    }
}
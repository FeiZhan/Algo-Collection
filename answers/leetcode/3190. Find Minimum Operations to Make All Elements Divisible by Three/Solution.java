class Solution {
    public int minimumOperations(int[] nums) {
        int result = 0;
        for (int number : nums) {
            result += number % 3 != 0 ? 1 : 0;
        }

        return result;
    }
}
class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        int count = 0;
        for (int number : nums) {
            count += number % 2 == 0 ? 1 : 0;
            if (count >= 2) {
                return true;
            }
        }

        return false;
    }
}
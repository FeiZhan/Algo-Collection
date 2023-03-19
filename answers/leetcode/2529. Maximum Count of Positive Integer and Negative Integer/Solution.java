class Solution {
    public int maximumCount(int[] nums) {
        int positive = 0;
        int negative = 0;

        for (int number : nums) {
            if (number > 0) {
                positive++;
            } else if (number < 0) {
                negative++;
            }
        }

        return Math.max(positive, negative);
    }
}
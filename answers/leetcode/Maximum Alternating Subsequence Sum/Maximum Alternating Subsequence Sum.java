class Solution {
    public long maxAlternatingSum(int[] nums) {
        long even = 0;
        long odd = 0;

        for (long number : nums) {
            long newEven = Math.max(number, odd + number);
            long newOdd = Math.max(0, even - number);
            even = Math.max(even, newEven);
            odd = Math.max(odd, newOdd);
        }

        return Math.max(even, odd);
    }
}
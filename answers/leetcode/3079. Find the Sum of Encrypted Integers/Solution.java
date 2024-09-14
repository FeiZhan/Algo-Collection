class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int result = 0;
        for (int number : nums) {
            int ones = 0;
            int maxDigit = 0;
            while (number != 0) {
                int digit = number % 10;
                maxDigit = Math.max(maxDigit, digit);
                ones = ones * 10 + 1;
                number /= 10;
            }
            result += ones * maxDigit;
        }

        return result;
    }
}
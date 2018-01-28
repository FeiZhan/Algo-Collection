class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0) {
            int[] number = new int[digits.length + 1];
            number[0] = carry;
            for (int i = 0; i < digits.length; i++) {
                number[i + 1] = digits[i];
            }
            return number;
        } else {
            return digits;
        }
    }
}
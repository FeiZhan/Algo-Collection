class Solution {
    public int alternateDigitSum(int n) {
        boolean sign = true;
        int result = 0;
        while (n != 0) {
            result += n % 10 * (sign ? 1 : -1);
            n /= 10;
            sign = !sign;
        }
        return result * (sign ? -1 : 1);
    }
}
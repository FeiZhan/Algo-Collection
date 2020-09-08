class Solution {
    public int[] getNoZeroIntegers(int n) {
        int tens = 1;
        int[] result = new int[2];
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            boolean carry = digit <= 1;
            if (carry && n > 0) {
                digit += 10;
                n--;
            }
            int half = digit == 19 ? 8 : digit / 2;
            result[0] += half * tens;
            result[1] += (digit - half) * tens;
            tens *= 10;
        }
        return result;
    }
}
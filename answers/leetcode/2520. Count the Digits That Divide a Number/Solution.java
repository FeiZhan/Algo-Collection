class Solution {
    public int countDigits(int num) {
        int digits = num;
        int count = 0;

        while (digits > 0) {
            int digit = digits % 10;
            digits /= 10;
            count += num % digit == 0 ? 1 : 0;
        }

        return count;
    }
}
class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return Integer.MAX_VALUE;
        }
        int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
        long dividend1 = Math.abs((long) dividend);
        long divisor1 = Math.abs((long) divisor);
        long result = recursiveDivide(dividend1, divisor1);
        if (result > Integer.MAX_VALUE && sign > 0) {
            return Integer.MAX_VALUE;
        } else {
            return (int) result * sign;
        }
    }
    
    private long recursiveDivide(long dividend, long divisor) {
        if (dividend < divisor) {
            return 0l;
        }
        long sum = divisor;
        long multiple = 1;
        while (sum + sum <= dividend) {
            sum += sum;
            multiple += multiple;
        }
        return multiple + this.recursiveDivide(dividend - sum, divisor);
    }
}
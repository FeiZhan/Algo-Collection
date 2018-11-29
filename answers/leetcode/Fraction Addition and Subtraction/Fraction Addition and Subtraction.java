class Solution {
    public String fractionAddition(String expression) {
        String[] split = expression.split("(?=[-+])");
        long numerator = 0l;
        long denominator = 1l;
        for (String fraction : split) {
            String[] splitFraction = fraction.split("\\/");
            int n = Integer.parseInt(splitFraction[0]);
            int d = Integer.parseInt(splitFraction[1]);
            numerator = numerator * d + n * denominator;
            denominator *= d;
            if (numerator != 0l) {
                long gcd = this.GCD(numerator, denominator);
                numerator /= gcd;
                denominator /= gcd;
                if (denominator < 0) {
                    numerator *= -1;
                    denominator *= -1;
                }
            } else {
                denominator = 1l;
            }
        }
        StringBuilder result = new StringBuilder();
        result.append(numerator).append("/").append(denominator);
        return result.toString();
    }

    private long GCD(long a, long b) {
        return b == 0l ? a : GCD(b, a%b);
    }
}
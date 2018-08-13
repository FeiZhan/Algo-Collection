class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        long numerator1 = (long) numerator;
        long denominator1 = (long) denominator;
        StringBuilder sb = new StringBuilder();
        sb.append(numerator1 * denominator1 < 0 ? "-" : "");
        numerator1 = Math.abs(numerator1);
        denominator1 = Math.abs((long) denominator1);
        sb.append(numerator1 / denominator1);
        if (numerator1 % denominator1 != 0) {
            sb.append(".");
            long remainder = numerator1 % denominator1;
            Map<Long, Integer> remainders = new HashMap<>();
            numerator1 = remainder * 10;
            remainders.put(remainder, sb.length());
            while (numerator1 > 0) {
                remainder = numerator1 % denominator1;
                sb.append(numerator1 / denominator1);
                if (remainders.containsKey(remainder)) {
                    sb.insert(remainders.get(remainder), "(").append(")");
                    break;
                } else {
                    remainders.put(remainder, sb.length());
                    numerator1 = remainder * 10;
                }
            }
        }
        return sb.toString();
    }
}
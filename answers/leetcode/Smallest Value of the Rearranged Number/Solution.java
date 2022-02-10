class Solution {
    public long smallestNumber(long num) {
        boolean isPositive = num >= 0;
        num = Math.abs(num);
        List<Integer> digits = new ArrayList<>();
        while (num > 0) {
            digits.add((int) (num % 10));
            num /= 10;
        }
        Collections.sort(digits);

        long result = 0;
        if (isPositive) {
            for (int i = 0; i < digits.size(); i++) {
                int digit = digits.get(i);
                if (digit > 0) {
                    result = digit;
                    digits.remove(i);
                    break;
                }
            }
            for (int digit : digits) {
                result = result * 10 + digit;
            }
        } else {
            for (int i = digits.size() - 1; i >= 0; i--) {
                result = result * 10 + digits.get(i);
            }
            result = -result;
        }

        return result;
    }
}
//Runtime: 4 ms, faster than 63.07% of Java online submissions for Smallest Value of the Rearranged Number.
//Memory Usage: 41.3 MB, less than 48.30% of Java online submissions for Smallest Value of the Rearranged Number.

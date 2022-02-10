class Solution {
    public int minimumSum(int num) {
        List<Integer> digits = new ArrayList<>();
        while (num > 0) {
            int digit = num % 10;
            digits.add(digit);
            num /= 10;
        }

        Collections.sort(digits);
        return (digits.get(0) + digits.get(1)) * 10 + digits.get(2) + digits.get(3);
    }
}
//Runtime: 0 ms, faster than 100.00% of Java online submissions for Minimum Sum of Four Digit Number After Splitting Digits.
//Memory Usage: 39 MB, less than 96.11% of Java online submissions for Minimum Sum of Four Digit Number After Splitting Digits.

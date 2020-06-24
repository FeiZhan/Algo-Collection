class Solution {
    public int maxDiff(int num) {
        List<Integer> digits = new ArrayList<>();
        while (num != 0) {
            digits.add(num % 10);
            num /= 10;
        }
        Collections.reverse(digits);
        int maxChange = -1;
        int minChange = -1;
        int minChangeTo = -1;
        int diff = 0;
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits.get(i);
            int max = digit;
            int min = digit;
            if (maxChange < 0 && digit < 9) {
                maxChange = digit;
            }
            if (digit == maxChange) {
                max = 9;
            }
            if (minChange < 0 && digit > 1) {
                minChange = digit;
                minChangeTo = i == 0 ? 1 : 0;
            }
            if (digit == minChange) {
                min = minChangeTo;
            }
            diff = diff * 10 + max - min;
        }
        return diff;
    }
}
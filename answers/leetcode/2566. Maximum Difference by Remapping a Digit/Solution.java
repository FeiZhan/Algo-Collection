class Solution {
    public int minMaxDifference(int num) {
        List<Integer> digits = new ArrayList<>();
        while (num > 0) {
            digits.add(0, num % 10);
            num /= 10;
        }
        int max = 0;
        int maxChange = -1;
        int min = 0;
        int minChange = -1;
        for (int digit : digits) {
            if (maxChange == -1 && digit < 9) {
                maxChange = digit;
            }
            max = max * 10 + (digit == maxChange ? 9 : digit);
            if (minChange == -1 && digit > 0) {
                minChange = digit;
            }
            min = min * 10 + (digit == minChange ? 0 : digit);
        }

        return max - min;
    }
}
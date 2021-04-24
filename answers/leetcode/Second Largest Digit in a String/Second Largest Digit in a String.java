class Solution {
    public int secondHighest(String s) {
        int first = -1;
        int second = -1;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int digit = Character.getNumericValue(c);
                if (digit > first) {
                    second = first;
                    first = digit;
                } else if (digit < first && digit > second) {
                    second = digit;
                }
            }
        }

        return second;
    }
}
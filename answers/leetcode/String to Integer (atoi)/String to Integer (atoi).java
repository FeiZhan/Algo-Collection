class Solution {
    public int myAtoi(String str) {
        boolean start = false;
        boolean negative = false;
        int number = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if ((c == ' ' || c == '\t') && !start) {
                continue;
            } else if (c == '+' && !start) {
                start = true;
            } else if (c == '-' && !start) {
                negative = true;
                start = true;
            } else if (Character.isDigit(c)) {
                start = true;
                int digit = Character.getNumericValue(c);
                if (number > Integer.MAX_VALUE / 10
                    || (number == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)) {
                    return negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                }
                number = number * 10 + digit;
            } else {
                break;
            }
        }
        return number * (negative ? -1 : 1);
    }
}
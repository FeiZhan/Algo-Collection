class Solution {
    public String convertToBase7(int num) {
        boolean negative = num < 0;
        if (negative) {
            num *= -1;
        }
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num % 7);
            num /= 7;
        }
        if (negative) {
            sb.append('-');
        }
        if (sb.length() == 0) {
            sb.append('0');
        }
        return sb.reverse().toString();
    }
}
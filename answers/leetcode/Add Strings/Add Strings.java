class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < num1.length() || i < num2.length(); i++) {
            int num = carry;
            if (i < num1.length()) {
                num += Character.getNumericValue(num1.charAt(num1.length() - 1 - i));
            }
            if (i < num2.length()) {
                num += Character.getNumericValue(num2.charAt(num2.length() - 1 - i));
            }
            sb.insert(0, num % 10);
            carry = num / 10;
        }
        while (carry > 0) {
            sb.insert(0, carry % 10);
            carry = carry / 10;
        }
        return sb.toString();
    }
}
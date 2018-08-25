class Solution {
    public String multiply(String num1, String num2) {
        int[] result = new int[num1.length() + num2.length() + 1];
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int multiplied = Character.getNumericValue(num1.charAt(i)) * Character.getNumericValue(num2.charAt(j));
                int index = num1.length() - 1 - i + num2.length() - 1 - j;
                result[index] += multiplied;
            }
        }
        int carry = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++) {
            result[i] += carry;
            carry = result[i] / 10;
            result[i] = result[i] % 10;
            sb.insert(0, result[i]);
        }
        while (sb.charAt(0) == '0' && sb.length() > 1) {
            sb.deleteCharAt(0);
        }
        return sb.toString();
    }
}
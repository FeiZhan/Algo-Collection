class Solution {
    public String addBinary(String a, String b) {
        int RADIX = 2;
        StringBuilder result = new StringBuilder();
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += Character.getNumericValue(a.charAt(i));
                i--;
            }
            if (j >= 0) {
                sum += Character.getNumericValue(b.charAt(j));
                j--;
            }
            result.append(Character.forDigit(sum % RADIX, RADIX));
            carry = sum / RADIX;
            System.out.println("sum: " + sum + " carry: " + carry);
        }
        while (carry > 0) {
            result.append(Character.forDigit(carry % RADIX, RADIX));
            carry /= RADIX;
        }
        return result.reverse().toString();
    }
}
class Solution {
    public String digitSum(String s, int k) {
        StringBuilder sb = new StringBuilder(s);
        while (sb.length() > k) {
            StringBuilder next = new StringBuilder();
            for (int i = 0; i < sb.length(); i += k) {
                int number = 0;
                for (int j = 0; j < k && i + j < sb.length(); j++) {
                    number += Character.getNumericValue(sb.charAt(i + j));
                }
                next.append(number);
            }
            sb = next;
        }

        return sb.toString();
    }
}
//Runtime: 1 ms, faster than 80.00% of Java online submissions for Calculate Digit Sum of a String.
//Memory Usage: 40.7 MB, less than 80.00% of Java online submissions for Calculate Digit Sum of a String.

class Solution {
    public String makeSmallestPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i * 2 < s.length(); i++) {
            int j = s.length() - i - 1;
            char left = s.charAt(i);
            char right = s.charAt(j);
            if (left < right) {
                sb.setCharAt(j, left);
            } else if (left > right) {
                sb.setCharAt(i, right);
            }
        }

        return sb.toString();
    }
}
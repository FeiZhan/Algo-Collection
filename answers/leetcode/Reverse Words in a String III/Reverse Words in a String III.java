class Solution {
    public String reverseWords(String s) {
        if (null == s) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0, j = 0; j <= s.length(); j++) {
            if (j == s.length() || ' ' == s.charAt(j)) {
                if (i < j) {
                    StringBuilder reverse = new StringBuilder(s.substring(i, j)).reverse();
                    sb.append(reverse);
                }
                if (j < s.length()) {
                    sb.append(" ");
                }
                i = j + 1;
            }
        }
        return sb.toString();
    }
}
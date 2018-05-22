public class Solution {
    public String reverseWords(String s) {
        if (null == s) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0, j = 1; j <= s.length(); j++) {
            if (s.charAt(i) == ' ' && j < s.length() && s.charAt(j) != ' ') {
                if (i > 0) {
                    sb.insert(0, " ");
                }
                i = j;
            } else if (s.charAt(i) != ' ' && (j == s.length() || s.charAt(j) == ' ')) {
                sb.insert(0, s.substring(i, j));
                i = j;
            }
        }
        return sb.toString();
    }
}
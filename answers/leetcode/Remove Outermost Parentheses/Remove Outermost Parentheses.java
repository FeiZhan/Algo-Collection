class Solution {
    public String removeOuterParentheses(String S) {
        int count = 0;
        int left = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == '(') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                sb.append(S.substring(left + 1, i));
                left = i + 1;
            }
        }
        return sb.toString();
    }
}
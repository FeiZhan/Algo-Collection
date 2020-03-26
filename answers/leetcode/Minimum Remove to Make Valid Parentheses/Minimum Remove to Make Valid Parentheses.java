class Solution {
    public String minRemoveToMakeValid(String s) {
        int left = 0;
        StringBuilder result = new StringBuilder(s);
        for (int i = 0; i < result.length(); i++) {
            char c = result.charAt(i);
            left += c == '(' ? 1 : c == ')' ? -1 : 0;
            if (left < 0) {
                result.deleteCharAt(i);
                i--;
                left = 0;
            }
        }
        int right = 0;
        for (int i = result.length() - 1; i >= 0; i--) {
            char c = result.charAt(i);
            right += c == ')' ? 1 : c == '(' ? -1 : 0;
            if (right < 0) {
                result.deleteCharAt(i);
                right = 0;
            }
        }
        return result.toString();
    }
}
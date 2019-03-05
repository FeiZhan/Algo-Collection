class Solution {
    public String reverseOnlyLetters(String S) {
        int left = 0;
        int right = S.length() - 1;
        StringBuilder sb = new StringBuilder(S);
        while (left < right) {
            if (!Character.isAlphabetic(S.charAt(left))) {
                left++;
            } else if (!Character.isAlphabetic(S.charAt(right))) {
                right--;
            } else {
                sb.setCharAt(left, S.charAt(right));
                sb.setCharAt(right, S.charAt(left));
                left++;
                right--;
            }
        }
        return sb.toString();
    }
}
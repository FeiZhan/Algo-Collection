class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() <= 1) {
            return "";
        }
        StringBuilder sb = new StringBuilder(palindrome);
        for (int i = 0; i < palindrome.length(); i++) {
            if (palindrome.charAt(i) != 'a' && i * 2 + 1 != palindrome.length()) {
                sb.setCharAt(i, 'a');
                return sb.toString();
            }
        }
        sb.setCharAt(palindrome.length() - 1, 'b');
        return sb.toString();
    }
}
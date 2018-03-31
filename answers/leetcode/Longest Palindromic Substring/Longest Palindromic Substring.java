class Solution {
    public String longestPalindrome(String s) {
        int maxLength = 0;
        String longest = "";
        for (int i = 0; i < s.length(); i++) {
            int x = i;
            int y = i;
            while (x >= 0 && y < s.length() && s.charAt(x) == s.charAt(y)) {
                if (y - x + 1 > maxLength) {
                    maxLength = y - x + 1;
                    longest = s.substring(x, y + 1);
                }
                x--;
                y++;
            }
            x = i;
            y = i + 1;
            while (x >= 0 && y < s.length() && s.charAt(x) == s.charAt(y)) {
                if (y - x + 1 > maxLength) {
                    maxLength = y - x + 1;
                    longest = s.substring(x, y + 1);
                }
                x--;
                y++;
            }
        }
        return longest;
    }
}
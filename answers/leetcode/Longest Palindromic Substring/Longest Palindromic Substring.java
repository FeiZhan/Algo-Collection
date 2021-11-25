class Solution {
    public String longestPalindrome(String s) {
        int left = 0;
        int right = 0;

        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            while (i - j >= 0 && i + j < s.length() && s.charAt(i - j) == s.charAt(i + j)) {
                j++;
            }
            if (j * 2 - 1 > right - left + 1) {
                left = i - j + 1;
                right = i + j - 1;
            }

            j = 0;
            while (i - j >= 0 && i + j + 1 < s.length() && s.charAt(i - j) == s.charAt(i + j + 1)) {
                j++;
            }
            if (j * 2 > right - left + 1) {
                left = i - j + 1;
                right = i + j;
            }
        }

        return s.substring(left, right + 1);
    }
}
//Runtime: 49 ms, faster than 48.66% of Java online submissions for Longest Palindromic Substring.
//Memory Usage: 39.9 MB, less than 45.36% of Java online submissions for Longest Palindromic Substring.

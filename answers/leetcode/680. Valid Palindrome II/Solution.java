class Solution {
    public boolean validPalindrome(String s) {
        if (null == s) {
            return true;
        }
        return validPalindrome(s, 0, s.length() - 1, false);
    }
    
    private boolean validPalindrome(String s, int left, int right, boolean deleted) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                if (deleted) {
                    return false;
                } else {
                    return validPalindrome(s, left + 1, right, true) || validPalindrome(s, left, right - 1, true);
                }
            }
            left++;
            right--;
        }
        return true;
    }
}
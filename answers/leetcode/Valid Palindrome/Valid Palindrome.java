class Solution {
    public boolean isPalindrome(String s) {
        if (null == s || s.length() == 0) {
            return true;
        }

        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (! Character.isLetter(s.charAt(left)) && ! Character.isDigit(s.charAt(left))) {
                left++;
            } else if (! Character.isLetter(s.charAt(right)) && ! Character.isDigit(s.charAt(right))) {
                right--;
            } else if (Character.toUpperCase(s.charAt(left)) != Character.toUpperCase(s.charAt(right))) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
}
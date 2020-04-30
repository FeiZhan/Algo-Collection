class Solution {
    public int removePalindromeSub(String s) {
        if (s == null || s.equals("")) {
            return 0;
        } else if (s.length() == 1) {
            return 1;
        }
        for (int i = 0; i * 2 < s.length(); i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return 2;
            }
        }
        return 1;
    }
}
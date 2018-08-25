class Solution {
    public String shortestPalindrome(String s) {
        int right;
        for (right = s.length() - 1; right >= 0; right--) {
            if (s.charAt(right) == s.charAt(0)) {
                boolean isPalin = true;
                for (int i = 0; i * 2 < right; i++) {
                    if (s.charAt(i) != s.charAt(right - i)) {
                        isPalin = false;
                        break;
                    }
                }
                if (isPalin) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(s.substring(right + 1))
                        .reverse()
                        .append(s);
                    return sb.toString();
                }
            }
        }
        return s;
    }
}
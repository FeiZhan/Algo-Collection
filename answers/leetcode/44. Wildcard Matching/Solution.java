class Solution {
    public boolean isMatch(String s, String p) {
        int i = 0;
        int j = 0;
        int starIndex = -1;
        int matchIndex = -1;

        while (i < s.length() || j < p.length()) {
            if (i < s.length() && j < p.length() && (p.charAt(j) == '?' || s.charAt(i) == p.charAt(j))) {
                i++;
                j++;
            } else if (j < p.length() && p.charAt(j) == '*') {
                matchIndex = i;
                starIndex = j;
                j++;
            } else if (i < s.length() && starIndex >= 0) {
                matchIndex++;
                i = matchIndex;
                j = starIndex + 1;
            } else {
                return false;
            }
        }

        return true;
    }
}
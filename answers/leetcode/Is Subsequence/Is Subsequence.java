class Solution {
    public boolean isSubsequence(String s, String t) {
        int sIndex = 0;
        for (char c : t.toCharArray()) {
            if (sIndex >= s.length()) {
                break;
            } else if (c == s.charAt(sIndex)) {
                sIndex++;
            }
        }
        return sIndex >= s.length();
    }
}
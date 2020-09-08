class Solution {
    public int maxPower(String s) {
        int previous = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != s.charAt(previous)) {
                max = Math.max(max, i - previous);
                previous = i;
            }
        }
        return Math.max(max, s.length() - previous);
    }
}
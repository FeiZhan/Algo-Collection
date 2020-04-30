class Solution {
    public int maxScore(String s) {
        int current = 0;
        for (char c : s.toCharArray()) {
            current += c == '1' ? 1 : 0;
        }
        int max = 0;
        for (int i = 0; i + 1 < s.length(); i++) {
            char  c = s.charAt(i);
            current += c == '0' ? 1 : -1;
            max = Math.max(max, current);
        }
        return max;
    }
}
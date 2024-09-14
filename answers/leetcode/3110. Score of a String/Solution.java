class Solution {
    public int scoreOfString(String s) {
        int result = 0;
        for (int i = 1; i < s.length(); i++) {
            result += Math.abs(s.charAt(i - 1) - s.charAt(i));
        }

        return result;
    }
}
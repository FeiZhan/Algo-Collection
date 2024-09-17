class Solution {
    public int longestContinuousSubstring(String s) {
        int left = 0;
        int result = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) + 1 != s.charAt(i)) {
                left = i;
            }
            result = Math.max(result, i - left + 1);
        }

        return result;
    }
}
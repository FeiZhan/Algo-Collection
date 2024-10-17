class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int duplicateIndex = -1;
        int left = 0;
        int result = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == s.charAt(i)) {
                if (duplicateIndex >= 0) {
                    left = duplicateIndex;
                }
                duplicateIndex = i;
            }
            result = Math.max(result, i - left + 1);
        }

        return result;
    }
}
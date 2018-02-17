class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder formatted = new StringBuilder();
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) != '-') {
                formatted.insert(0, S.charAt(i));
            }
            if (formatted.length() % (K + 1) == K) {
                formatted.insert(0, '-');
            }
        }
        if (formatted.length() > 0 && formatted.charAt(0) == '-') {
            formatted.delete(0, 1);
        }
        return formatted.toString().toUpperCase();
    }
}
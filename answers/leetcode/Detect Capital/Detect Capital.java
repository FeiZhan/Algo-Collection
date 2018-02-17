class Solution {
    public boolean detectCapitalUse(String word) {
        boolean hasUppercase = false;
        boolean hasLowercase = false;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (!hasUppercase && i > 0 && Character.isUpperCase(c)) {
                hasUppercase = true;
                if (hasLowercase) {
                    return false;
                }
            }
            if (!hasLowercase && Character.isLowerCase(c)) {
                hasLowercase = true;
                if (hasUppercase) {
                    return false;
                }
            }
        }
        return true;
    }
}
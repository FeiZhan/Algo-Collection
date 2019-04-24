class Solution {

    private static final String BASE = "abc";

    public boolean isValid(String S) {
        while (S.length() > 0) {
            if (S.indexOf(BASE) >= 0) {
                S = S.replace(BASE, "");
            } else {
                return false;
            }
        }
        return true;
    }
}
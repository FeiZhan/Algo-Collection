class Solution {
    public boolean isSubstringPresent(String s) {
        String reversed = new StringBuilder(s).reverse().toString();
        for (int i = 1; i < s.length(); i++) {
            String sub = s.substring(i - 1, i + 1);
            if (reversed.contains(sub)) {
                return true;
            }
        }

        return false;
    }
}
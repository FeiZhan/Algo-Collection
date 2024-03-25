class Solution {
    public int countKeyChanges(String s) {
        int result = 0;
        for (int i = 1; i < s.length(); i++) {
            char c = Character.toLowerCase(s.charAt(i));
            char c1 = Character.toLowerCase(s.charAt(i - 1));
            if (c != c1) {
                result++;
            }
        }

        return result;
    }
}
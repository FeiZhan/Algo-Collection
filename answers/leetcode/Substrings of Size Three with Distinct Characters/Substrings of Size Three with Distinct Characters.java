class Solution {
    public int countGoodSubstrings(String s) {
        int count = 0;
        for (int i = 2; i < s.length(); i++) {
            char c0 = s.charAt(i - 2);
            char c1 = s.charAt(i - 1);
            char c2 = s.charAt(i);
            if (c0 != c1 && c1 != c2 && c0 != c2) {
                count++;
            }
        }

        return count;
    }
}
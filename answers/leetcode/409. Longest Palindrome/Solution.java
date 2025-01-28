class Solution {
    public int longestPalindrome(String s) {
        Set<Character> letters = new HashSet<Character>();
        for (char c : s.toCharArray()) {
            if (letters.contains(c)) {
                letters.remove(c);
            } else {
                letters.add(c);
            }
        }
        return s.length() - letters.size() + (letters.size() == 0 ? 0 : 1);
    }
}
class Solution {
    public int minimizedStringLength(String s) {
        Set<Character> charSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            charSet.add(c);
        }

        return charSet.size();
    }
}
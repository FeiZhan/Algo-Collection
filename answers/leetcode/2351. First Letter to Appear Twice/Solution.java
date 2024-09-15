class Solution {
    public char repeatedCharacter(String s) {
        Set<Character> charSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (charSet.contains(c)) {
                return c;
            }
            charSet.add(c);
        }

        return s.charAt(0);
    }
}
class Solution {
    public int numberOfSpecialChars(String word) {
        Set<Character> charSet = new HashSet<>();
        for (char c : word.toCharArray()) {
            charSet.add(c);
        }
        
        int result = 0;
        for (char c : charSet) {
            if (Character.isLowerCase(c) && charSet.contains(Character.toUpperCase(c))) {
                result++;
            }
        }

        return result;
    }
}
class Solution {
    public int vowelStrings(String[] words, int left, int right) {
        final Set<Character> VOWELS = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int count = 0;
        for (int i = left; i <= right && i < words.length; i++) {
            String word = words[i];
            if (word.length() > 0 && VOWELS.contains(word.charAt(0)) && VOWELS.contains(word.charAt(word.length() - 1))) {
                count++;
            }
        }

        return count;
    }
}
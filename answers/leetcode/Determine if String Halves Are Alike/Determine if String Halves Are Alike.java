class Solution {

    private static final String VOWELS = "aeiouAEIOU";

    public boolean halvesAreAlike(String s) {
        int length = s.length();
        return this.countVowels(s, 0, length / 2) == this.countVowels(s, length / 2, length);
    }

    private int countVowels(String text, int left, int right) {
        int count = 0;
        for (int i = left; i < right; i++) {
            char c = text.charAt(i);
            if (VOWELS.indexOf(c) >= 0) {
                count++;
            }
        }

        return count;
    }
}
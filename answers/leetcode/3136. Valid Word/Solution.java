class Solution {
    public boolean isValid(String word) {
        if (word == null || word.length() < 3) {
            return false;
        }

        final Set<Character> VOWELS = new HashSet<>();
        VOWELS.add('a');
        VOWELS.add('e');
        VOWELS.add('i');
        VOWELS.add('o');
        VOWELS.add('u');
        VOWELS.add('A');
        VOWELS.add('E');
        VOWELS.add('I');
        VOWELS.add('O');
        VOWELS.add('U');

        boolean haveVowel = false;
        boolean haveConsonant = false;
        for (char c : word.toCharArray()) {
            if (Character.isLetter(c)) {
                if (VOWELS.contains(c)) {
                    haveVowel = true;
                } else {
                    haveConsonant = true;
                }
            } else if (!Character.isDigit(c)) {
                return false;
            }
        }

        return haveVowel && haveConsonant;
    }
}
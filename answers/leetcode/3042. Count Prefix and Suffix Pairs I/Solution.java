class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int length = words.length;
        int result = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                result += isPrefixAndSuffix(words[i], words[j]) ? 1 : 0;
            }
        }

        return result;
    }

    private boolean isPrefixAndSuffix(String substring, String text) {
        if (substring == null || text == null || substring.length() > text.length()) {
            return false;
        }

        int length = substring.length();
        return substring.equals(text.substring(0, length)) && substring.equals(text.substring(text.length() - length));
    }
}
class Solution {
    public String longestWord(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length).thenComparing(Object::toString));
        String result = "";
        Set<String> wordSet = new HashSet<>();
        for (String word : words) {
            String substring = word.substring(0, word.length() - 1);
            if (word.length() == 1 || wordSet.contains(substring)) {
                wordSet.add(word);
                if (result.length() < word.length()) {
                    result = word;
                }
            }
        }

        return result;
    }
}
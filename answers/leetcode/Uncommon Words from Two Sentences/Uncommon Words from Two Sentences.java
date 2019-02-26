class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> words = new HashMap<>();
        String[] split = A.split(" ");
        for (String word : split) {
            words.put(word, words.getOrDefault(word, 0) + 1);
        }
        split = B.split(" ");
        for (String word : split) {
            words.put(word, words.getOrDefault(word, 0) + 1);
        }
        List<String> uncommon = new LinkedList<>();
        for (String word : words.keySet()) {
            if (words.get(word) == 1) {
                uncommon.add(word);
            }
        }
        return uncommon.toArray(new String[uncommon.size()]);
    }
}
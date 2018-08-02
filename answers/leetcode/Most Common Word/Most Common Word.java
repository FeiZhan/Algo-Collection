class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> bannedSet = new HashSet<>(Arrays.asList(banned));
        Map<String, Integer> wordCount = new HashMap<>();
        String mostCommon = "";
        String[] words = paragraph.split(" ");
        for (String word : words) {
            word = word.toLowerCase().replaceAll("\\p{Punct}|\\d", "");
            if (!bannedSet.contains(word)) {
                wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
                if (!wordCount.containsKey(mostCommon) || wordCount.get(mostCommon) < wordCount.get(word)) {
                    mostCommon = word;
                }
            }
        }
        return mostCommon;
    }
}
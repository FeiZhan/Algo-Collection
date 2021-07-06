class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        Map<Character, Integer> word1Map = new HashMap<>();
        for (char c : word1.toCharArray()) {
            word1Map.put(c, word1Map.getOrDefault(c, 0) + 1);
        }
        Map<Character, Integer> word2Map = new HashMap<>();
        for (char c : word2.toCharArray()) {
            word2Map.put(c, word2Map.getOrDefault(c, 0) + 1);
        }
        if (!word1Map.keySet().equals(word2Map.keySet())) {
            return false;
        }
        List<Integer> counts1 = new ArrayList<>(word1Map.values());
        Collections.sort(counts1);
        List<Integer> counts2 = new ArrayList<>(word2Map.values());
        Collections.sort(counts2);
        return counts1.equals(counts2);
    }
}
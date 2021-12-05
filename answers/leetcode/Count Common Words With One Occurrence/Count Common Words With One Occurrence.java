class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> countMap1 = new HashMap<>();
        for (String word : words1) {
            countMap1.put(word, countMap1.getOrDefault(word, 0) + 1);
        }

        Map<String, Integer> countMap2 = new HashMap<>();
        for (String word : words2) {
            countMap2.put(word, countMap2.getOrDefault(word, 0) + 1);
        }

        int result = 0;
        for (String word : countMap1.keySet()) {
            if (countMap1.get(word) == 1 && countMap2.getOrDefault(word, 0) == 1) {
                result++;
            }
        }

        return result;
    }
}
//Runtime: 11 ms, faster than 14.88% of Java online submissions for Count Common Words With One Occurrence.
//Memory Usage: 43.6 MB, less than 15.57% of Java online submissions for Count Common Words With One Occurrence.

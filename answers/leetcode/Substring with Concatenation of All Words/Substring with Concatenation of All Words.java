class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> found = new LinkedList<>();
        if (s == null || words == null || words.length == 0) {
            return found;
        }
        int length = words[0].length();
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }
        for (int i = 0; i + length * words.length <= s.length(); i++) {
            int allCount = 0;
            Map<String, Integer> visitMap = new HashMap<>();
            int left = i;
            for (int j = i + length - 1; j < s.length() && j <= left + length; j++) {
                String subStr = s.substring(left, j + 1);
                int count = visitMap.getOrDefault(subStr, 0);
                if (wordMap.containsKey(subStr) && wordMap.get(subStr) > count) {
                    visitMap.put(subStr, count + 1);
                    allCount++;
                    left = j + 1;
                }
                if (allCount == words.length) {
                    found.add(i);
                    break;
                }
            }
        }
        return found;
    }
}
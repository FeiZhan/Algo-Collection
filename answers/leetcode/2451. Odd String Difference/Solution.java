class Solution {
    public String oddString(String[] words) {
        Map<String, List<String>> wordMap = new HashMap<>();
        for (String word : words) {
            char lowest = 'z';
            for (char c : word.toCharArray()) {
                lowest = (char) Math.min((int) lowest, (int) c);
            }
            StringBuilder sb = new StringBuilder();
            for (char c : word.toCharArray()) {
                sb.append((char) (c - (lowest - 'a')));
            }
            String updated = sb.toString();
            List<String> wordList = wordMap.getOrDefault(updated, new LinkedList<>());
            wordList.add(word);
            wordMap.put(updated, wordList);
        }
        for (String word : wordMap.keySet()) {
            List<String> wordList = wordMap.get(word);
            if (wordList.size() == 1) {
                return wordList.get(0);
            }
        }
        return "";
    }
}
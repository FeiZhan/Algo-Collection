class Solution {
    public int similarPairs(String[] words) {
        Map<String, List<Integer>> wordMap = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            Set<Character> charSet = new HashSet<>();
            StringBuilder sb = new StringBuilder();
            for (char c : words[i].toCharArray()) {
                if (!charSet.contains(c)) {
                    charSet.add(c);
                    sb.append(c);
                }
            }
            char[] chars = sb.toString().toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            List<Integer> wordIndexes = wordMap.getOrDefault(sorted, new LinkedList<>());
            wordIndexes.add(i);
            wordMap.put(sorted, wordIndexes);
        }

        int count = 0;
        for (List<Integer> wordIndexes : wordMap.values()) {
            int size = wordIndexes.size();
            count += size * (size - 1) / 2;
        }

        return count;
    }
}
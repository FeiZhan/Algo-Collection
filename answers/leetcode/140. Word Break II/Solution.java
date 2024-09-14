class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Map<Integer, Set<String>> lengthMap = new HashMap<>();
        for (String word : wordDict) {
            int length = word.length();
            Set<String> set = lengthMap.getOrDefault(length, new HashSet<>());
            set.add(word);
            lengthMap.put(length, set);
        }

        Map<Integer, List<String>> indexMap = new HashMap<>();
        List<String> temp = new LinkedList<>();
        temp.add("");
        indexMap.put(s.length(), temp);
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!indexMap.containsKey(i + 1)) {
                continue;
            }
            List<String> nextList = indexMap.get(i + 1);
            for (int length : lengthMap.keySet()) {
                int start = i - length + 1;
                if (start < 0) {
                    continue;
                }
                String sub = s.substring(start, i + 1);
                if (lengthMap.get(length).contains(sub)) {
                    List<String> list = indexMap.getOrDefault(start, new LinkedList<>());
                    for (String next : nextList) {
                        String current = sub + (next.length() > 0 ? " " + next : "");
                        list.add(current);
                    }
                    indexMap.put(start, list);
                }
            }
        }
        
        return indexMap.getOrDefault(0, Collections.emptyList());
    }
}
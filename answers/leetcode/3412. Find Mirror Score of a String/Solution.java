class Solution {
    public long calculateScore(String s) {
        long result = 0l;
        Map<Character, List<Integer>> charMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            char mirror = (char)(25 - c + 'a' + 'a');
            if (charMap.containsKey(mirror)) {
                List<Integer> indexes = charMap.get(mirror);
                result += i - indexes.get(indexes.size() - 1);
                indexes.remove(indexes.size() - 1);
                if (indexes.isEmpty()) {
                    charMap.remove(mirror);
                }
            } else {
                List<Integer> indexes = charMap.getOrDefault(c, new LinkedList<>());
                indexes.add(i);
                charMap.put(c, indexes);
            }
        }

        return result;
    }
}
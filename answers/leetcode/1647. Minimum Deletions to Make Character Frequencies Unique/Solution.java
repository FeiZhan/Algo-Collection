class Solution {
    public int minDeletions(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }

        int maxCount = 0;
        Map<Integer, List<Character>> countChars = new HashMap<>();
        for (char c : counts.keySet()) {
            int count = counts.get(c);
            maxCount = Math.max(maxCount, count);
            List<Character> chars = countChars.getOrDefault(count, new LinkedList<>());
            chars.add(c);
            countChars.put(count, chars);
        }

        SortedSet<Integer> empty = new TreeSet<>();
        for (int i = 1; i < maxCount; i++) {
            if (!countChars.containsKey(i)) {
                empty.add(i);
            }
        }

        int result = 0;
        for (int count : countChars.keySet()) {
            List<Character> chars = countChars.get(count);
            for (int i = 1; i < chars.size(); i++) {
                SortedSet<Integer> headSet = empty.headSet(count);
                if (headSet.size() > 0) {
                    int previous = headSet.last();
                    result += count - previous;
                    empty.remove(previous);
                } else {
                    result += count;
                }
            }
        }

        return result;
    }
}
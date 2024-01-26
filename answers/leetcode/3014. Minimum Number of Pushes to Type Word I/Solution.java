import java.util.SortedMap;

class Solution {
    public int minimumPushes(String word) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : word.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }

        SortedMap<Integer, List<Character>> charMap = new TreeMap<>(Collections.reverseOrder());
        for (char c : counts.keySet()) {
            int count = counts.get(c);
            List<Character> chars = charMap.getOrDefault(count, new LinkedList<>());
            chars.add(c);
            charMap.put(count, chars);
        }

        int push = 0;
        int result = 0;
        for (int count : charMap.keySet()) {
            List<Character> chars = charMap.get(count);
            int size = chars.size();
            while (size >= 8) {
                push++;
                result += push * count * 8;
                size -= 8;
            }
            if (size > 0) {
                push++;
                result += push * count * size;
            }
        }

        return result;
    }
}
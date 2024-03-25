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

        int size = 0;
        int push = 1;
        int result = 0;
        for (int count : charMap.keySet()) {
            List<Character> chars = charMap.get(count);
            for (char c : chars) {
                size++;
                if (size > 8) {
                    push++;
                    size -= 8;
                }
                result += count * push;
                //System.out.println(c + " " + count + " " + size + " " + push + " " + result);
            }
        }

        return result;
    }
}
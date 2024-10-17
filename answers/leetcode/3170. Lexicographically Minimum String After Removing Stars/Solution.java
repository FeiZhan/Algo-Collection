import java.util.SortedMap;

class Solution {
    public String clearStars(String s) {
        StringBuilder sb = new StringBuilder(s);
        SortedMap<Character, PriorityQueue<Integer>> charMap = new TreeMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '*') {
                if (!charMap.isEmpty()) {
                    char firstChar = charMap.firstKey();
                    PriorityQueue<Integer> queue = charMap.get(firstChar);
                    int index = queue.poll();
                    sb.setCharAt(index, '*');
                    if (queue.isEmpty()) {
                        charMap.remove(firstChar);
                    }
                }
            } else {
                PriorityQueue<Integer> queue = charMap.getOrDefault(c, new PriorityQueue<>(Collections.reverseOrder()));
                queue.add(i);
                charMap.put(c, queue);
            }
        }

        String result = sb.toString();
        return result.replaceAll("\\*", "");
    }
}
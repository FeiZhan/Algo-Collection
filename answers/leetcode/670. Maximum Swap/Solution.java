import java.util.SortedMap;

class Solution {
    public int maximumSwap(int num) {
        StringBuilder sb = new StringBuilder();
        sb.append(num);
        Map<Character, Integer> countMap = new HashMap<>();
        SortedMap<Character, Integer> indexMap = new TreeMap<>();
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
            indexMap.put(c, i);
        }

        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            countMap.put(c, countMap.get(c) - 1);
            if (countMap.get(c) == 0) {
                countMap.remove(c);
                indexMap.remove(c);
            }
            if (!indexMap.isEmpty()) {
                char last = indexMap.lastKey();
                if (last > c) {
                    int index = indexMap.get(last);
                    sb.setCharAt(i, last);
                    sb.setCharAt(index, c);
                    return Integer.parseInt(sb.toString());
                }
            }
        }

        return num;
    }
}
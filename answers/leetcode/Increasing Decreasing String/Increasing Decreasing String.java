import java.util.SortedMap;

class Solution {
    public String sortString(String s) {
        SortedMap<Character, Integer> ascending = new TreeMap<>();
        SortedMap<Character, Integer> descending = new TreeMap<>(Collections.reverseOrder());
        for (char c : s.toCharArray()) {
            ascending.put(c, ascending.getOrDefault(c, 0) + 1);
            descending.put(c, descending.getOrDefault(c, 0) + 1);
        }
        StringBuilder sb = new StringBuilder();
        while (!ascending.isEmpty() || !descending.isEmpty()) {
            Set<Character> zeros = new HashSet<>();
            for (char c : ascending.keySet()) {
                int count = ascending.get(c);
                if (count > 0) {
                    sb.append(c);
                    count--;
                    ascending.put(c, count);
                    descending.put(c, count);
                }
                if (count == 0) {
                    zeros.add(c);
                }
            }
            for (char c : descending.keySet()) {
                int count = descending.get(c);
                if (count > 0) {
                    sb.append(c);
                    count--;
                    ascending.put(c, count);
                    descending.put(c, count);
                }
                if (count == 0) {
                    zeros.add(c);
                }
            }
            for (char c : zeros) {
                ascending.remove(c);
                descending.remove(c);
            }
        }
        return sb.toString();
    }
}
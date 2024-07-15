import java.util.SortedMap;

class Solution {
    public int beautySum(String s) {
        int length = s.length();
        int result = 0;
        for (int i = 0; i < length; i++) {
            Map<Character, Integer> letterMap = new HashMap<>();
            SortedMap<Integer, Set<Character>> countMap = new TreeMap<>();
            for (int j = i; j < length; j++) {
                char c = s.charAt(j);
                if (letterMap.containsKey(c)) {
                    int count = letterMap.get(c);
                    Set<Character> set = countMap.get(count);
                    set.remove(c);
                    if (set.isEmpty()) {
                        countMap.remove(count);
                    }
                }
                letterMap.put(c, letterMap.getOrDefault(c, 0) + 1);
                int count = letterMap.get(c);
                Set<Character> set = countMap.getOrDefault(count, new HashSet<>());
                set.add(c);
                countMap.put(count, set);
                result += countMap.lastKey() - countMap.firstKey();
            }
        }

        return result;
    }
}
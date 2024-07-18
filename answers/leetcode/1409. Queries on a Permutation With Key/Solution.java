import java.util.SortedMap;

class Solution {
    public int[] processQueries(int[] queries, int m) {
        Map<Integer, Integer> numberMap = new HashMap<>();
        SortedMap<Integer, Integer> indexMap = new TreeMap<>();
        for (int i = 0; i < m; i++) {
            numberMap.put(i + 1, i);
            indexMap.put(i, i + 1);
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int query = queries[i];
            int index = numberMap.get(query);
            result[i] = index;
            int newIndex = 1;
            SortedMap<Integer, Integer> headMap = new TreeMap<>(indexMap.headMap(index));
            for (int headIndex : headMap.keySet()) {
                int headNumber = headMap.get(headIndex);
                numberMap.put(headNumber, newIndex);
                indexMap.put(newIndex, headNumber);
                newIndex++;
            }
            numberMap.put(query, 0);
            indexMap.put(0, query);
        }

        return result;
    }
}
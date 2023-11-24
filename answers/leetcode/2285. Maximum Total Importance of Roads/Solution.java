import java.util.SortedMap;

class Solution {
    public long maximumImportance(int n, int[][] roads) {
        Map<Integer, Long> counts = new HashMap<>();
        for (int[] road : roads) {
            for (int index : road) {
                counts.put(index, counts.getOrDefault(index, 0l) + 1l);
            }
        }

        SortedMap<Long, List<Integer>> sortedCounts = new TreeMap<>(Collections.reverseOrder());
        for (int index : counts.keySet()) {
            long count = counts.get(index);
            List<Integer> indexes = sortedCounts.getOrDefault(count, new LinkedList<>());
            indexes.add(index);
            sortedCounts.put(count, indexes);
        }

        Map<Integer, Integer> values = new HashMap<>();
        for (List<Integer> indexes : sortedCounts.values()) {
            for (int index : indexes) {
                values.put(index, n);
                n--;
            }
        }

        long result = 0l;
        for (int[] road : roads) {
            for (int index : road) {
                result += values.get(index);
            }
        }

        return result;
    }
}
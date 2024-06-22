import java.util.SortedMap;

class Solution {
    public int minimumDeletions(String word, int k) {
        int maxCount = 0;
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : word.toCharArray()) {
            int count = counts.getOrDefault(c, 0) + 1;
            counts.put(c, count);
            maxCount = Math.max(maxCount, count);
        }

        SortedMap<Integer, Integer> countCounts = new TreeMap<>();
        for (int count : counts.values()) {
            countCounts.put(count, countCounts.getOrDefault(count, 0) + 1);
        }

        int headDeletion = 0;
        int result = Integer.MAX_VALUE;
        for (int minCount : countCounts.keySet()) {
            int deletion = headDeletion;
            SortedMap<Integer, Integer> tail = countCounts.tailMap(minCount + k);
            for (int tailCount : tail.keySet()) {
                deletion += (tailCount - minCount - k) * tail.get(tailCount);
            }
            result = Math.min(result, deletion);
            headDeletion += minCount * countCounts.get(minCount);
        }

        return result;
    }
}
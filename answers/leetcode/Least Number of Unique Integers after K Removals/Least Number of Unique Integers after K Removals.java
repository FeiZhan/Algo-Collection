import java.util.SortedMap;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : arr) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        SortedMap<Integer, List<Integer>> reverseCounts = new TreeMap<>();
        for (int number : counts.keySet()) {
            int count = counts.get(number);
            List<Integer> list = reverseCounts.getOrDefault(count, new LinkedList<>());
            list.add(number);
            reverseCounts.put(count, list);
        }
        while (k > 0) {
            int count = reverseCounts.firstKey();
            List<Integer> list = reverseCounts.get(count);
            if (k < count) {
                break;
            }
            int number = list.get(0);
            counts.remove(number);
            list.remove(0);
            if (list.isEmpty()) {
                reverseCounts.remove(count);
            }
            k -= count;
        }
        return counts.size();
    }
}
import java.util.SortedMap;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        SortedMap<Integer, Integer> counts = new TreeMap<>();
        for (int number : arr) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        int rank = 1;
        Map<Integer, Integer> ranks = new HashMap<>();
        for (int number : counts.keySet()) {
            ranks.put(number, rank);
            rank++;
        }
        int[] result = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            result[i] = ranks.get(arr[i]);
        }
        return result;
    }
}
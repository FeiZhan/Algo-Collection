import java.util.SortedMap;

class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int median = arr[(arr.length - 1) / 2];
        SortedMap<Integer, PriorityQueue<Integer>> differences = new TreeMap<>();
        for (int number : arr) {
            int difference = Math.abs(number - median);
            PriorityQueue<Integer> queue = differences.getOrDefault(difference, new PriorityQueue<>(Collections.reverseOrder()));
            queue.add(number);
            differences.put(difference, queue);
        }
        int index = 0;
        int[] result = new int[k];
        while (index < k) {
            int lastKey = differences.lastKey();
            PriorityQueue<Integer> queue = differences.get(lastKey);
            while (index < k && !queue.isEmpty()) {
                result[index] = queue.poll();
                index++;
            }
            if (queue.isEmpty()) {
                differences.remove(lastKey);
            }
        }
        return result;
    }
}
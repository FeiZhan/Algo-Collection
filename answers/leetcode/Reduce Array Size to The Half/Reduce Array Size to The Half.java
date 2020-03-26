class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : arr) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> queue = new PriorityQueue<>((e1, e2) -> (e2.getValue() - e1.getValue()));
        queue.addAll(counts.entrySet());
        int size = arr.length;
        int result = 0;
        while (size * 2 > arr.length) {
            Map.Entry<Integer, Integer> entry = queue.poll();
            size -= entry.getValue();
            result++;
        }
        return result;
    }
}
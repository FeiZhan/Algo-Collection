class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> queue = new PriorityQueue<>((a, b) -> (b.getValue() - a.getValue()));
        for (Map.Entry<Integer, Integer> entry : numMap.entrySet()) {
            queue.add(entry);
        }
        List<Integer> top = new LinkedList<>();
        while (top.size() < k) {
            top.add(queue.poll().getKey());
        }
        return top;
    }
}
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> countMap = new HashMap<>();
        for (String word : words) {
            countMap.put(word, countMap.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> heap = new PriorityQueue<>((word1, word2) -> {
            int count = countMap.get(word1) - countMap.get(word2);
            return count != 0 ? count : word2.compareTo(word1);
        });
        for (String word : countMap.keySet()) {
            heap.add(word);
            if (heap.size() > k) {
                heap.poll();
            }
        }
        List<String> result = new ArrayList<>();
        while (!heap.isEmpty()) {
            result.add(heap.poll());
        }
        Collections.reverse(result);
        return result;
    }
}
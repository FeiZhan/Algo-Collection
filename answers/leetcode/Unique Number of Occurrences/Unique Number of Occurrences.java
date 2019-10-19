class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> occurrences = new HashMap<>();
        for (int num : arr) {
            occurrences.put(num, occurrences.getOrDefault(num, 0) + 1);
        }
        Set<Integer> unique = new HashSet<>(occurrences.values());
        return unique.size() == occurrences.size();
    }
}
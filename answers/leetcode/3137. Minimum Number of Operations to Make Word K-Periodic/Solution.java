class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        Map<String, Integer> counts = new HashMap<>();
        for (int i = 0; i < word.length(); i += k) {
            String substring = word.substring(i, i + k);
            counts.put(substring, counts.getOrDefault(substring, 0) + 1);
        }

        int maxCount = 0;
        for (int count : counts.values()) {
            maxCount = Math.max(maxCount, count);
        }

        return word.length() / k - maxCount;
    }
}
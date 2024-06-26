import java.util.SortedMap;

class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        int length = nums.length;
        long[] result = new long[length];
        Map<Integer, Long> counts = new HashMap<>();
        SortedMap<Long, Set<Integer>> numbers = new TreeMap<>(Collections.reverseOrder());

        for (int i = 0; i < length; i++) {
            int number = nums[i];
            if (counts.containsKey(number)) {
                long count = counts.get(number);
                Set<Integer> numberSet = numbers.get(count);
                numberSet.remove(number);
                if (numberSet.isEmpty()) {
                    numbers.remove(count);
                }
            }
            long count = counts.getOrDefault(number, 0l) + (long)freq[i];
            counts.put(number, count);
            Set<Integer> numberSet = numbers.getOrDefault(count, new HashSet<>());
            numberSet.add(number);
            numbers.put(count, numberSet);
            result[i] = numbers.firstKey();
        }

        return result;
    }
}
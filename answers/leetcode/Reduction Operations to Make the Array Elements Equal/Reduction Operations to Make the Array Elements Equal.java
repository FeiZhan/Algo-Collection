import java.util.SortedMap;

class Solution {
    public int reductionOperations(int[] nums) {
        SortedMap<Integer, Integer> counts = new TreeMap<>(Collections.reverseOrder());

        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }

        int previous = 0;
        int result = 0;
        for (int count : counts.values()) {
            result += previous;
            previous += count;
        }

        return result;
    }
}
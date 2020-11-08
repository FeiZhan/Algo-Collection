import java.util.SortedMap;
import java.util.SortedSet;

class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> frequencies = new HashMap<>();
        for (int num : nums) {
            frequencies.put(num, frequencies.getOrDefault(num, 0) + 1);
        }
        SortedMap<Integer, SortedSet<Integer>> numMap = new TreeMap<>();
        for (int number : frequencies.keySet()) {
            int frequency = frequencies.get(number);
            SortedSet<Integer> set = numMap.getOrDefault(frequency, new TreeSet<>(Collections.reverseOrder()));
            set.add(number);
            numMap.put(frequency, set);
        }
        int[] result = new int[nums.length];
        int index = 0;
        for (int frequency : numMap.keySet()) {
            SortedSet<Integer> set = numMap.get(frequency);
            for (int number : set) {
                for (int i = 0; i < frequency; i++) {
                    result[index] = number;
                    index++;
                }
            }
        }
        return result;
    }
}
import java.util.SortedMap;

class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        SortedMap<Integer, Integer> counts = new TreeMap<>();
        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        int sum = 0;
        Map<Integer, Integer> sums = new HashMap<>();
        for (int num : counts.keySet()) {
            sums.put(num, sum);
            sum += counts.get(num);
        }
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            result[i] = sums.getOrDefault(nums[i], 0);
        }
        return result;
    }
}
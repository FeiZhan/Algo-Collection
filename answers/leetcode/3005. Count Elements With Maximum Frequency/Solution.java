class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> frequency = new HashMap<>();
        for (int number : nums) {
            frequency.put(number, frequency.getOrDefault(number, 0) + 1);
        }

        int max = 0;
        int result = 0;
        for (int count : frequency.values()) {
            if (count > max) {
                max = count;
                result = count;
            } else if (count == max) {
                result += count;
            }
        }

        return result;
    }
}
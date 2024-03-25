class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : nums) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }

        int result = 0;
        for (int count : counts.values()) {
            if (count == 1) {
                return -1;
            }
            result += count / 3 + (count % 3 > 0 ? 1 : 0);
        }

        return result;
    }
}
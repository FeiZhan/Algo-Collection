class Solution {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : nums) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        int result = 0;
        for (int count : counts.values()) {
            if (count > 1) {
                result += (count - 1) * count / 2;
            }
        }
        return result;
    }
}
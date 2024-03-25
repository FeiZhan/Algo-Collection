class Solution {
    public int minimumIndex(List<Integer> nums) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : nums) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }

        Map<Integer, Integer> leftCounts = new HashMap<>();
        for (int i = 0; i < nums.size(); i++) {
            int number = nums.get(i);
            leftCounts.put(number, leftCounts.getOrDefault(number, 0) + 1);
            int leftCount = leftCounts.get(number);
            if (leftCount * 2 > i + 1 && (counts.get(number) - leftCount) * 2 > nums.size() - i - 1) {
                return i;
            }
        }

        return -1;
    }
}
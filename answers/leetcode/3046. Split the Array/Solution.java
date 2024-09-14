class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        Map<Integer, Integer> numberMap = new HashMap<>();
        for (int number : nums) {
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
            if (numberMap.get(number) > 2) {
                return false;
            }
        }

        return true;
    }
}
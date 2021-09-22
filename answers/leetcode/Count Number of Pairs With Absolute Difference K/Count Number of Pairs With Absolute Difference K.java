class Solution {
    public int countKDifference(int[] nums, int k) {
        int result = 0;
        Map<Integer, Integer> numberMap = new HashMap<>();

        for (int number : nums) {
            result += numberMap.getOrDefault(number + k, 0) + numberMap.getOrDefault(number - k, 0);
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
        }

        return result;
    }
}
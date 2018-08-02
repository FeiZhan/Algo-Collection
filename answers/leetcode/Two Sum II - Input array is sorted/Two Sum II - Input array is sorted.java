class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        Map<Integer, Integer> numberMap = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            if (numberMap.containsKey(target - numbers[i])) {
                result[0] = numberMap.get(target - numbers[i]) + 1;
                result[1] = i + 1;
                break;
            }
            numberMap.put(numbers[i], i);
        }
        return result;
    }
}
class Solution {
    public int sumOfUnique(int[] nums) {
        Map<Integer, Boolean> numbers = new HashMap<>();

        for (int number : nums) {
            boolean isExisting = numbers.containsKey(number);
            numbers.put(number, isExisting);
        }

        int sum = 0;
        for (int number : numbers.keySet()) {
            boolean isDuplicate = numbers.get(number);
            if (!isDuplicate) {
                sum += number;
            }
        }

        return sum;
    }
}
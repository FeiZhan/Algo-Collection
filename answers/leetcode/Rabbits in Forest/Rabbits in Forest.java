class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> numbers = new HashMap<>();
        for (int answer : answers) {
            numbers.put(answer, numbers.getOrDefault(answer, 0) + 1);
        }
        int result = 0;
        for (int number : numbers.keySet()) {
            int count = numbers.get(number);
            while (count > 0) {
                result += number + 1;
                count -= number + 1;
            }
        }
        return result;
    }
}
class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> result = new LinkedList<>();
        for (int number : nums) {
            List<Integer> digits = new LinkedList<>();
            while (number != 0) {
                digits.add(0, number % 10);
                number /= 10;
            }
            result.addAll(digits);
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
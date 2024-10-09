class Solution {
    public int minElement(int[] nums) {
        int result = Integer.MAX_VALUE;
        for (int number : nums) {
            int sum = 0;
            while (number > 0) {
                sum += number % 10;
                number /= 10;
            }
            result = Math.min(result, sum);
        }

        return result;
    }
}
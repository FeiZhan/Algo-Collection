class Solution {
    public int differenceOfSum(int[] nums) {
        int elementSum = 0;
        int digitSum = 0;
        for (int number : nums) {
            elementSum += number;
            while (number > 0) {
                digitSum += number % 10;
                number /= 10;
            }
        }

        return Math.abs(elementSum - digitSum);
    }
}
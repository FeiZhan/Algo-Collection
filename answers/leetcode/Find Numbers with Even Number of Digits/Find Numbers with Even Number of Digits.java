class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int number : nums) {
            int digits = 0;
            while (number > 0) {
                digits++;
                number /= 10;
            }
            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
}
class Solution {
    public int countPartitions(int[] nums) {
        int sum = 0;
        for (int number : nums) {
            sum += number;
        }
        return sum % 2 == 0 ? nums.length - 1 : 0;
    }
}
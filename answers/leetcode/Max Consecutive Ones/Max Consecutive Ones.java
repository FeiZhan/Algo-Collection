class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int current = 0;
        for (int num : nums) {
            if (1 == num) {
                current += 1;
            } else {
                max = Math.max(max, current);
                current = 0;
            }
        }
        return Math.max(max, current);
    }
}
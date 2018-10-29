class Solution {
    public int minMoves(int[] nums) {
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int num : nums) {
            sum += num;
            min = Math.min(min, num);
        }
        return sum - nums.length * min;
    }
}
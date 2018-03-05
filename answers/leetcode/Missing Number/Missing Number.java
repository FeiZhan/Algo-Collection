class Solution {
    public int missingNumber(int[] nums) {
        return (nums.length * (nums.length + 1) / 2) - IntStream.of(nums).sum();
    }
}
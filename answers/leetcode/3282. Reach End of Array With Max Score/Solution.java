class Solution {
    public long findMaximumScore(List<Integer> nums) {
        int max = 0;
        long result = 0;
        for (int number : nums) {
            result += max;
            max = Math.max(max, number);
        }

        return result;
    }
}
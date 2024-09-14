class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        double result = Double.MAX_VALUE;
        for (int i = 0; i + i < nums.length; i++) {
            result = Math.min(result, (nums[i] + nums[nums.length - i - 1]) / 2.0);
        }

        return result;
    }
}
class Solution {
    public long largestPerimeter(int[] nums) {
        long sum = 0l;
        for (int number : nums) {
            sum += (long)number;
        }

        Arrays.sort(nums);
        for (int i = nums.length - 1; i >= 0; i--) {
            long number = (long)nums[i];
            if (sum > number + number) {
                return sum;
            }
            sum -= number;
        }

        return -1;
    }
}
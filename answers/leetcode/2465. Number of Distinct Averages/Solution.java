class Solution {
    public int distinctAverages(int[] nums) {
        Arrays.sort(nums);
        Set<Double> result = new HashSet<>();

        for (int i = 0; i * 2 < nums.length; i++) {
            double average = (nums[i] + nums[nums.length - i - 1]) / 2.0;
            result.add(average);
        }

        return result.size();
    }
}
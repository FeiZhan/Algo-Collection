class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        int sum = 0;
        for (int number : nums) {
            sum += number;
        }
        Arrays.sort(nums);
        int subsequence = 0;
        List<Integer> result = new LinkedList<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            subsequence += nums[i];
            result.add(nums[i]);
            if (subsequence * 2 > sum) {
                break;
            }
        }
        return result;
    }
}
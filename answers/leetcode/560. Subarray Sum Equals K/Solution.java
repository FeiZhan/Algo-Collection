class Solution {
    public int subarraySum(int[] nums, int k) {
        int length = nums.length;
        int result = 0;
        int[] sums = new int[length];
        for (int i = 0; i < length; i++) {
            sums[i] = nums[i] + (i > 0 ? sums[i - 1] : 0);
            result += sums[i] == k ? 1 : 0;
        }
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                result += sums[j] - sums[i] == k ? 1 : 0;
            }
        }

        return result;
    }
}
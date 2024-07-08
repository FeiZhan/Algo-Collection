class Solution {
    public long maxArrayValue(int[] nums) {
        long merged = (long) nums[nums.length - 1];
        long result = merged;
        for (int i = nums.length - 2; i >= 0; i--) {
            merged = (long)nums[i] + (nums[i] <= merged ? merged : 0l);
            result = Math.max(result, merged);
        }

        return result;
    }
}
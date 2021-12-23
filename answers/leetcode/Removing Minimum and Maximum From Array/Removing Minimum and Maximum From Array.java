class Solution {
    public int minimumDeletions(int[] nums) {
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        int result = Integer.MAX_VALUE;
        result = Math.min(result, Math.max(minIndex, maxIndex) + 1);
        result = Math.min(result, nums.length - Math.min(minIndex, maxIndex));
        result = Math.min(result, minIndex + 1 + nums.length - maxIndex);
        result = Math.min(result, maxIndex + 1 + nums.length - minIndex);

        return result;
    }
}
//Runtime: 6 ms, faster than 12.99% of Java online submissions for Removing Minimum and Maximum From Array.
//Memory Usage: 109.7 MB, less than 35.77% of Java online submissions for Removing Minimum and Maximum From Array.

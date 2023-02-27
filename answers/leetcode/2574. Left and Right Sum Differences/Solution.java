class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int sum = 0;
        int[] leftSum = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            leftSum[i] = sum;
            sum += nums[i];
        }

        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int right = sum - nums[i] - leftSum[i];
            result[i] = Math.abs(leftSum[i] - right);
        }

        return result;
    }
}
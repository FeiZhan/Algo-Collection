class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] diff = new int[nums.length + 1];
        for (int[] query : queries) {
            diff[query[0]] += 1;
            diff[query[1] + 1] -= 1;
        }
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += diff[i];
            if (nums[i] > sum) {
                return false;
            }
        }

        return true;
    }
}
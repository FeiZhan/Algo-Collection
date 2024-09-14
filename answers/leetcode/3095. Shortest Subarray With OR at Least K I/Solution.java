class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int[] orList = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; i + j < nums.length; j++) {
                orList[j] |= nums[i + j];
                if (orList[j] >= k) {
                    return i + 1;
                }
            }
        }

        return -1;
    }
}
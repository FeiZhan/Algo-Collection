class Solution {
    public int jump(int[] nums) {
        int currentMax = 0;
        int nextMax = 0;
        int count = 0;
        for (int i = 0; i + 1 < nums.length && i <= currentMax; i++) {
            nextMax = Math.max(nextMax, i + nums[i]);
            if (i >= currentMax) {
                currentMax = nextMax;
                count++;
            }
        }
        return count;
    }
}
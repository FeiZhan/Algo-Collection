class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] sum = new int[2];
        for (int i = 0; i < cost.length; i++) {
            int newSum = cost[i] + Math.min(sum[0], sum[1]);
            sum[0] = sum[1];
            sum[1] = newSum;
        }
        return Math.min(sum[0], sum[1]);
    }
}
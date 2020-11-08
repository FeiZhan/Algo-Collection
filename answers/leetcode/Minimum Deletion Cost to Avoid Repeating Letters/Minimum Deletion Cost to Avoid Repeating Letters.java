class Solution {
    public int minCost(String s, int[] cost) {
        int result = 0;
        int maxCost = cost[0];
        int sum = cost[0];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == s.charAt(i)) {
                maxCost = Math.max(maxCost, cost[i]);
                sum += cost[i];
            } else {
                result += sum - maxCost;
                maxCost = cost[i];
                sum = cost[i];
            }
        }
        return result + sum - maxCost;
    }
}
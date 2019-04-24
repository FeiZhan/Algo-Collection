class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, Comparator.comparingInt(cost -> cost[0] - cost[1]));
        int total = 0;
        for (int i = 0; i < costs.length; i++) {
            total += costs[i][i * 2 < costs.length ? 0 : 1];
        }
        return total;
    }
}
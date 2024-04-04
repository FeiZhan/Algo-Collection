class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {
        int[][] cost = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid[grid.length - 1].length; i++) {
            cost[grid.length - 1][i] = grid[grid.length - 1][i];
        }

        for (int i = grid.length - 2; i >= 0; i--) {
            for (int j = 0; j < grid[i].length; j++) {
                int minCost = Integer.MAX_VALUE;
                int[] moveCostList = moveCost[grid[i][j]];
                for (int k = 0; k < moveCostList.length; k++) {
                    minCost = Math.min(minCost, moveCostList[k] + cost[i + 1][k]);
                    //System.out.println(i + " " + j + " " + grid[i][j] + " : " + k + " " + moveCostList[k] + " " + cost[i + 1][j] + " : " + minCost);
                }
                cost[i][j] = minCost + grid[i][j];
            }
        }

        int result = Integer.MAX_VALUE;
        for (int temp : cost[0]) {
            result = Math.min(result, temp);
        }

        return result;
    }
}
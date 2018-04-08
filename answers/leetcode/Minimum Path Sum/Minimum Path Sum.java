class Solution {
    public int minPathSum(int[][] grid) {
        List<List<Integer>> sums = new ArrayList<List<Integer>>();
        for (int i = 0; i < grid.length; i++) {
            sums.add(new ArrayList<Integer>());
            for (int j = 0; j < grid[i].length; j++) {
                int minPath = Integer.MAX_VALUE;
                if (i > 0) {
                    minPath = Math.min(minPath, sums.get(i - 1).get(j));
                }
                if (j > 0) {
                    minPath = Math.min(minPath, sums.get(i).get(j - 1));
                }
                if (minPath == Integer.MAX_VALUE) {
                    minPath = 0;
                }
                sums.get(i).add(minPath + grid[i][j]);
            }
        }
        return sums.get(grid.length - 1).get(grid[0].length - 1);
    }
}
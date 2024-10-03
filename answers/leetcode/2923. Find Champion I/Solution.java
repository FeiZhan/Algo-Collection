class Solution {
    public int findChampion(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            boolean flag = true;
            for (int j = 0; j < grid[i].length; j++) {
                if (i == j) {
                    continue;
                } else if (grid[i][j] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }

        return -1;
    }
}
class Solution {
    public int[][] findFarmland(int[][] land) {
        List<int[]> groups = new LinkedList<>();
        for (int i = 0; i < land.length; i++) {
            for (int j = 0; j < land[i].length; j++) {
                int[] group = new int[]{Integer.MAX_VALUE, Integer.MAX_VALUE, -1, -1};
                if (dfs(i, j, group, land)) {
                    groups.add(group);
                }
            }
        }

        int[][] result = new int[groups.size()][4];
        for (int i = 0; i < result.length; i++) {
            result[i] = groups.get(i);
        }

        return result;
    }

    private boolean dfs(int x, int y, int[] group, int[][] land) {
        if (x < 0 || x >= land.length || y < 0 || y >= land[x].length || land[x][y] != 1) {
            return false;
        }

        group[0] = Math.min(group[0], x);
        group[1] = Math.min(group[1], y);
        group[2] = Math.max(group[2], x);
        group[3] = Math.max(group[3], y);
        land[x][y] = 2;
        dfs(x - 1, y, group, land);
        dfs(x + 1, y, group, land);
        dfs(x, y - 1, group, land);
        dfs(x, y + 1, group, land);

        return true;
    }
}
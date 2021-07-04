class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        Map<Integer, Integer> rootMap = new HashMap<>();
        for (int i = 0; i < grid1.length; i++) {
            for (int j = 0; j < grid1[i].length; j++) {
                int id = i * 1000 + j;
                if (grid1[i][j] == 1 && !rootMap.containsKey(id)) {
                    this.dfs(i, j, rootMap, id, grid1);
                }
            }
        }

        int result = 0;
        boolean[][] visited = new boolean[grid2.length][grid2[0].length];
        for (int i = 0; i < grid2.length; i++) {
            for (int j = 0; j < grid2[i].length; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    int id = i * 1000 + j;
                    int rootId = rootMap.getOrDefault(id, -1);
                    if (rootId >= 0) {
                        result += this.check(i, j, visited, rootId, rootMap, grid2);
                        //System.out.println(i + ", " + j + ": " + rootId + " " + result);
                    }
                }
            }
        }

        return result;
    }

    private void dfs(int x, int y, Map<Integer, Integer> rootMap, int rootId, int[][] grid) {
        int id = x * 1000 + y;
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] != 1 || rootMap.containsKey(id)) {
            return;
        }

        rootMap.put(id, rootId);
        this.dfs(x - 1, y, rootMap, rootId, grid);
        this.dfs(x + 1, y, rootMap, rootId, grid);
        this.dfs(x, y - 1, rootMap, rootId, grid);
        this.dfs(x, y + 1, rootMap, rootId, grid);
    }

    private int check(int x, int y, boolean[][] visited, int rootId, Map<Integer, Integer> rootMap, int[][] grid) {
        int id = x * 1000 + y;
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] != 1 || visited[x][y]) {
            return 1;
        } else if (rootMap.getOrDefault(id, -1) != rootId) {
            return 0;
        }

        visited[x][y] = true;
        int left = this.check(x - 1, y, visited, rootId, rootMap, grid);
        int right = this.check(x + 1, y, visited, rootId, rootMap, grid);
        int top = this.check(x, y - 1, visited, rootId, rootMap, grid);
        int bottom = this.check(x, y + 1, visited, rootId, rootMap, grid);

        return left == 1 && right == 1 && top == 1 && bottom == 1 ? 1 : 0;
    }
}
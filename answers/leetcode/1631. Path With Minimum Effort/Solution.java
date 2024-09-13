class Solution {
    public int minimumEffortPath(int[][] heights) {
        int right = 0;
        for (int[] row : heights) {
            for (int cell : row) {
                right = Math.max(right, cell);
            }
        }

        int left = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            int[][] copy = Arrays.stream(heights).map(int[]::clone).toArray(int[][]::new);
            boolean valid = dfs(0, 0, heights[0][0], middle, copy);
            if (valid) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }

    private boolean dfs(int x, int y, int previous, int effort, int[][] heights) {
        int height = heights.length;
        int width = heights[0].length;
        if (x < 0 || x >= height || y < 0 || y >= width || heights[x][y] < 0 || Math.abs(heights[x][y] - previous) > effort) {
            return false;
        } else if (x == height - 1 && y == width - 1) {
            return true;
        }

        int current = heights[x][y];
        heights[x][y] = -1;
        return dfs(x - 1, y, current, effort, heights) || dfs(x + 1, y, current, effort, heights)
            || dfs(x, y - 1, current, effort, heights) || dfs(x, y + 1, current, effort, heights);
    }
}
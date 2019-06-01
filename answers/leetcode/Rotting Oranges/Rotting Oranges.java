class Solution {
    public int orangesRotting(int[][] grid) {
        int freshCount = 0;
        Queue<int[]> nextQueue = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    freshCount++;
                } else if (grid[i][j] == 2) {
                    int[] position = new int[2];
                    position[0] = i;
                    position[1] = j;
                    nextQueue.add(position);
                }
            }
        }
        if (freshCount == 0) {
            return 0;
        }
        int minute = 0;
        while (!nextQueue.isEmpty()) {
            if (freshCount == 0) {
                return minute;
            }
            minute++;
            Queue<int[]> queue = new LinkedList<>(nextQueue);
            nextQueue.clear();
            while (!queue.isEmpty()) {
                int[] position = queue.poll();
                if (position[0] > 0 && grid[position[0] - 1][position[1]] == 1) {
                    freshCount--;
                    grid[position[0] - 1][position[1]] = 2;
                    int[] next = new int[2];
                    next[0] = position[0] - 1;
                    next[1] = position[1];
                    nextQueue.add(next);
                }
                if (position[0] + 1 < grid.length && grid[position[0] + 1][position[1]] == 1) {
                    freshCount--;
                    grid[position[0] + 1][position[1]] = 2;
                    int[] next = new int[2];
                    next[0] = position[0] + 1;
                    next[1] = position[1];
                    nextQueue.add(next);
                }
                if (position[1] > 0 && grid[position[0]][position[1] - 1] == 1) {
                    freshCount--;
                    grid[position[0]][position[1] - 1] = 2;
                    int[] next = new int[2];
                    next[0] = position[0];
                    next[1] = position[1] - 1;
                    nextQueue.add(next);
                }
                if (position[1] + 1 < grid[position[0]].length && grid[position[0]][position[1] + 1] == 1) {
                    freshCount--;
                    grid[position[0]][position[1] + 1] = 2;
                    int[] next = new int[2];
                    next[0] = position[0];
                    next[1] = position[1] + 1;
                    nextQueue.add(next);
                }
            }
        }
        return -1;
    }
}
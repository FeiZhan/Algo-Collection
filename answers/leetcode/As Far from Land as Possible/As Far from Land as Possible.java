class Solution {

    private class Point {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int maxDistance(int[][] grid) {
        int[][] distances = new int[grid.length][grid[0].length];
        Queue<Point> nextQueue = new LinkedList<>();
        for (int i = 0; i < distances.length; i++) {
            for (int j = 0; j < distances[i].length; j++) {
                distances[i][j] = Integer.MAX_VALUE;
                if (grid[i][j] == 1) {
                    nextQueue.add(new Point(i, j));
                }
            }
        }
        int distance = -1;
        while (!nextQueue.isEmpty()) {
            distance++;
            Queue<Point> queue = nextQueue;
            nextQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                Point current = queue.poll();
                if (current.x < 0 || current.x >= grid.length || current.y < 0 || current.y >= grid[0].length
                    || distances[current.x][current.y] <= distance) {
                    continue;
                }
                distances[current.x][current.y] = distance;
                nextQueue.add(new Point(current.x - 1, current.y));
                nextQueue.add(new Point(current.x + 1, current.y));
                nextQueue.add(new Point(current.x, current.y - 1));
                nextQueue.add(new Point(current.x, current.y + 1));
            }
        }
        int maxDistance = -1;
        for (int i = 0; i < distances.length; i++) {
            for (int j = 0; j < distances[i].length; j++) {
                //System.out.println(i + " " + j + ": " + distances[i][j]);
                if (grid[i][j] == 0 && distances[i][j] < Integer.MAX_VALUE) {
                    maxDistance = Math.max(maxDistance, distances[i][j]);
                }
            }
        }
        return maxDistance;
    }
}
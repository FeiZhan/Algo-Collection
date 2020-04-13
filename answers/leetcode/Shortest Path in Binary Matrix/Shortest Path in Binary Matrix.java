class Solution {

    private class Point {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int shortestPathBinaryMatrix(int[][] grid) {
        Queue<Point> nextQueue = new LinkedList<>();
        nextQueue.add(new Point(0, 0));
        int steps = 0;
        while (!nextQueue.isEmpty()) {
            steps++;
            Queue<Point> queue = nextQueue;
            nextQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                Point current = queue.poll();
                if (current.x < 0 || current.x >= grid.length
                    || current.y < 0 || current.y >= grid[0].length
                    || grid[current.x][current.y] == 1) {
                    continue;
                }
                if (current.x == grid.length - 1 && current.y == grid[0].length - 1) {
                    return steps;
                }
                grid[current.x][current.y] = 1;
                nextQueue.add(new Point(current.x - 1, current.y - 1));
                nextQueue.add(new Point(current.x - 1, current.y));
                nextQueue.add(new Point(current.x - 1, current.y + 1));
                nextQueue.add(new Point(current.x, current.y - 1));
                nextQueue.add(new Point(current.x, current.y + 1));
                nextQueue.add(new Point(current.x + 1, current.y - 1));
                nextQueue.add(new Point(current.x + 1, current.y));
                nextQueue.add(new Point(current.x + 1, current.y + 1));
            }
        }
        return -1;
    }
}
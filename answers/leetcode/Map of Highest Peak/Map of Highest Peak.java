import java.util.AbstractMap;

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int height = isWater.length;
        int width = isWater[0].length;
        Queue<Map.Entry<Integer, Integer>> nextQueue = new LinkedList<>();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (isWater[i][j] == 1) {
                    Map.Entry<Integer, Integer> cell = new AbstractMap.SimpleEntry<>(i, j);
                    nextQueue.add(cell);
                }
            }
        }

        int[][] result = new int[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                result[i][j] = Integer.MAX_VALUE;
            }
        }

        int zHeight = -1;
        while (!nextQueue.isEmpty()) {
            zHeight++;
            Queue<Map.Entry<Integer, Integer>> queue = new LinkedList<>(nextQueue);
            nextQueue.clear();

            while (!queue.isEmpty()) {
                Map.Entry<Integer, Integer> cell = queue.poll();
                int row = cell.getKey();
                int column = cell.getValue();
                if (row < 0 || row >= height || column < 0 || column >= width || result[row][column] <= zHeight) {
                    continue;
                }

                result[row][column] = zHeight;
                nextQueue.add(new AbstractMap.SimpleEntry<>(row - 1, column));
                nextQueue.add(new AbstractMap.SimpleEntry<>(row + 1, column));
                nextQueue.add(new AbstractMap.SimpleEntry<>(row, column - 1));
                nextQueue.add(new AbstractMap.SimpleEntry<>(row, column + 1));
            }
        }

        return result;
    }
}
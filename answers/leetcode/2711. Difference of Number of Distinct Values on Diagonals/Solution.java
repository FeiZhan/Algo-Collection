class Solution {
    public int[][] differenceOfDistinctValues(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int[][] result = new int[height][width];

        for (int i = 0; i < width; i++) {
            Map<Integer, Integer> bottomRight = new HashMap<>();
            for (int j = 0; j < height && i + j < width; j++) {
                int cell = grid[j][i + j];
                bottomRight.put(cell, bottomRight.getOrDefault(cell, 0) + 1);
            }
            Set<Integer> topLeft = new HashSet<>();
            for (int j = 0; j < height && i + j < width; j++) {
                int cell = grid[j][i + j];
                bottomRight.put(cell, bottomRight.getOrDefault(cell, 0) - 1);
                if (bottomRight.get(cell) == 0) {
                    bottomRight.remove(cell);
                }
                result[j][i + j] = Math.abs(topLeft.size() - bottomRight.size());
                topLeft.add(cell);
            }
        }

        for (int i = 1; i < height; i++) {
            Map<Integer, Integer> bottomRight = new HashMap<>();
            for (int j = 0; j < width && i + j < height; j++) {
                int cell = grid[i + j][j];
                bottomRight.put(cell, bottomRight.getOrDefault(cell, 0) + 1);
            }
            Set<Integer> topLeft = new HashSet<>();
            for (int j = 0; j < width && i + j < height; j++) {
                int cell = grid[i + j][j];
                bottomRight.put(cell, bottomRight.getOrDefault(cell, 0) - 1);
                if (bottomRight.get(cell) == 0) {
                    bottomRight.remove(cell);
                }
                result[i + j][j] = Math.abs(topLeft.size() - bottomRight.size());
                topLeft.add(cell);
            }
        }

        return result;
    }
}
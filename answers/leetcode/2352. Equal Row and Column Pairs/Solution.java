class Solution {
    public int equalPairs(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        Map<String, Integer> stringMap = new HashMap<>();
        for (int i = 0; i < height; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < width; j++) {
                sb.append(grid[i][j]).append(' ');
            }
            String str = sb.toString();
            stringMap.put(str, stringMap.getOrDefault(str, 0) + 1);
        }

        int result = 0;
        for (int i = 0; i < width; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < height; j++) {
                sb.append(grid[j][i]).append(' ');
            }
            String str = sb.toString();
            if (stringMap.containsKey(str)) {
                result += stringMap.get(str);
            }
        }

        return result;
    }
}
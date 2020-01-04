class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int height = grid.length;
        int width = grid[0].length;
        k = k % (height * width);
        int x = k / width;
        int y = k % width;
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < height; i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < width; j++) {
                list.add(0);
            }
            result.add(list);
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                result.get(x).set(y, grid[i][j]);
                y++;
                if (y >= width) {
                    y = 0;
                    x++;
                    if (x >= height) {
                        x = 0;
                    }
                }
            }
        }
        return result;
    }
}
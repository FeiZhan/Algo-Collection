class neighborSum {

    private int[][] grid = null;
    private Map<Integer, List<Integer>> coordinateMap = new HashMap<>();

    public neighborSum(int[][] grid) {
        this.grid = grid;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                list.add(j);
                coordinateMap.put(grid[i][j], list);
            }
        }
    }
    
    public int adjacentSum(int value) {
        List<Integer> coordinate = coordinateMap.get(value);
        int x = coordinate.get(0);
        int y = coordinate.get(1);
        return getValue(x - 1, y) + getValue(x + 1, y) + getValue(x, y - 1) + getValue(x, y + 1);
    }
    
    public int diagonalSum(int value) {
        List<Integer> coordinate = coordinateMap.get(value);
        int x = coordinate.get(0);
        int y = coordinate.get(1);
        return getValue(x - 1, y - 1) + getValue(x + 1, y - 1) + getValue(x - 1, y + 1) + getValue(x + 1, y + 1);
    }

    private int getValue(int x, int y) {
        return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length ? grid[x][y] : 0;
    }
}

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum obj = new neighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */
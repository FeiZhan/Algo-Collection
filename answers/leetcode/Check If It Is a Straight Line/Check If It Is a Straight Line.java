class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int[] base = new int[] {
            coordinates[1][0] - coordinates[0][0],
            coordinates[1][1] - coordinates[0][1]
        };
        for (int i = 2; i < coordinates.length; i++) {
            int[] numbers = new int[] {
                coordinates[i][0] - coordinates[0][0],
                coordinates[i][1] - coordinates[0][1]
            };
            if (numbers[0] * base[1] != numbers[1] * base[0]) {
                return false;
            }
        }
        return true;
    }
}
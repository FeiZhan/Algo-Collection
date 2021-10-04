class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (original == null || m * n != original.length) {
            return new int[0][];
        }

        int x = 0;
        int y = 0;
        int[][] result = new int[m][n];
        
        for (int i = 0; i < original.length; i++) {
            result[x][y] = original[i];
            y++;
            if (y >= n) {
                x++;
                y = 0;
            }
        }

        return result;
    }
}
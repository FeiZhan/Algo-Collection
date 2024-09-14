class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiagonal = 0;
        int area = 0;
        for (int[] dimension : dimensions) {
            int diagonal = dimension[0] * dimension[0] + dimension[1] * dimension[1];
            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                area = dimension[0] * dimension[1];
            } else if (diagonal == maxDiagonal) {
                area = Math.max(area, dimension[0] * dimension[1]);
            }
        }

        return area;
    }
}
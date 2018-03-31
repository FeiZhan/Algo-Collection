class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            this.floodFill(image, sr, sc, newColor, image[sr][sc]);
        }
        return image;
    }
    private void floodFill(int[][] image, int sr, int sc, int newColor, int oldColor) {
        if (sr >= 0 && sr < image.length && sc >= 0 && sc < image[sr].length && image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            this.floodFill(image, sr - 1, sc, newColor, oldColor);
            this.floodFill(image, sr + 1, sc, newColor, oldColor);
            this.floodFill(image, sr, sc - 1, newColor, oldColor);
            this.floodFill(image, sr, sc + 1, newColor, oldColor);
        }
    }
}
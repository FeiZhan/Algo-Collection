class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int maxLength = 0;
        for (int[] rectangle : rectangles) {
            int minLength = Math.min(rectangle[0], rectangle[1]);
            maxLength = Math.max(maxLength, minLength);
        }

        int count = 0;
        for (int[] rectangle : rectangles) {
            int minLength = Math.min(rectangle[0], rectangle[1]);
            if (minLength >= maxLength) {
                count++;
            }
        }

        return count;
    }
}
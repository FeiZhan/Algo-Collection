class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int current = 0;
        int length = cardPoints.length - k;
        int min = Integer.MAX_VALUE;
        int sum = 0;
        for (int i = 0; i < cardPoints.length; i++) {
            sum += cardPoints[i];
            current += cardPoints[i];
            if (i >= length) {
                current -= cardPoints[i - length];
            }
            if (i >= length - 1) {
                min = Math.min(min, current);
            }
        }
        return sum - min;
    }
}
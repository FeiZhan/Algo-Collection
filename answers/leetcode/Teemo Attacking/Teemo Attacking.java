class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int count = 0;
        for (int i = 1; i < timeSeries.length; i++) {
            count += Math.min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        if (timeSeries.length > 0) {
            count += duration;
        }
        return count;
    }
}